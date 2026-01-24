/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 */

#ifndef MATIEC_TYPES_TYPE_HPP
#define MATIEC_TYPES_TYPE_HPP

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace matiec::types {

enum class TypeCategory : uint8_t {
    Bool,
    Byte,
    Word,
    DWord,
    LWord,
    SInt,
    Int,
    DInt,
    LInt,
    USInt,
    UInt,
    UDInt,
    ULInt,
    Real,
    LReal,
    Time,
    Date,
    TimeOfDay,
    DateAndTime,
    String,
    WString,
    Array,
    Struct,
    Enum,
    Any,
    Invalid
};

namespace detail {

constexpr int integer_rank(TypeCategory category) noexcept {
    switch (category) {
        case TypeCategory::SInt: return 1;
        case TypeCategory::Int: return 2;
        case TypeCategory::DInt: return 3;
        case TypeCategory::LInt: return 4;
        case TypeCategory::USInt: return 1;
        case TypeCategory::UInt: return 2;
        case TypeCategory::UDInt: return 3;
        case TypeCategory::ULInt: return 4;
        default: return -1;
    }
}

constexpr int real_rank(TypeCategory category) noexcept {
    switch (category) {
        case TypeCategory::Real: return 1;
        case TypeCategory::LReal: return 2;
        default: return -1;
    }
}

constexpr bool is_integer(TypeCategory category) noexcept {
    return integer_rank(category) >= 0;
}

constexpr bool is_real(TypeCategory category) noexcept {
    return real_rank(category) >= 0;
}

} // namespace detail

class Type {
public:
    virtual ~Type() = default;

    [[nodiscard]] virtual TypeCategory category() const noexcept = 0;
    [[nodiscard]] virtual std::string_view name() const noexcept = 0;
    [[nodiscard]] virtual size_t sizeInBits() const noexcept = 0;

    [[nodiscard]] bool isInteger() const noexcept {
        return detail::is_integer(category());
    }

    [[nodiscard]] bool isReal() const noexcept {
        return detail::is_real(category());
    }

    [[nodiscard]] bool isNumeric() const noexcept {
        return isInteger() || isReal();
    }

    [[nodiscard]] virtual bool isCompatibleWith(const Type& other) const noexcept {
        return category() == other.category();
    }

    [[nodiscard]] virtual bool isAssignableTo(const Type& other) const noexcept {
        return isCompatibleWith(other);
    }
};

class ElementaryType final : public Type {
public:
    explicit ElementaryType(TypeCategory category) : category_(category) {}

    [[nodiscard]] TypeCategory category() const noexcept override { return category_; }
    [[nodiscard]] std::string_view name() const noexcept override;
    [[nodiscard]] size_t sizeInBits() const noexcept override;

    [[nodiscard]] bool isCompatibleWith(const Type& other) const noexcept override {
        if (category_ == other.category()) {
            return true;
        }
        return isAssignableTo(other);
    }

    [[nodiscard]] bool isAssignableTo(const Type& other) const noexcept override {
        if (category_ == other.category()) {
            return true;
        }
        if (detail::is_integer(category_) && detail::is_integer(other.category())) {
            return detail::integer_rank(category_) <= detail::integer_rank(other.category());
        }
        if (detail::is_integer(category_) && detail::is_real(other.category())) {
            return true;
        }
        if (detail::is_real(category_) && detail::is_real(other.category())) {
            return detail::real_rank(category_) <= detail::real_rank(other.category());
        }
        return false;
    }

private:
    TypeCategory category_;
};

class ArrayType final : public Type {
public:
    struct Dimension {
        int64_t lower = 0;
        int64_t upper = 0;

        [[nodiscard]] size_t size() const noexcept {
            return upper >= lower ? static_cast<size_t>(upper - lower + 1) : 0;
        }
    };

    ArrayType(std::shared_ptr<const Type> element_type, std::vector<Dimension> dims)
        : element_type_(std::move(element_type)), dimensions_(std::move(dims)) {}

    [[nodiscard]] TypeCategory category() const noexcept override { return TypeCategory::Array; }
    [[nodiscard]] std::string_view name() const noexcept override { return "ARRAY"; }
    [[nodiscard]] size_t sizeInBits() const noexcept override;

    [[nodiscard]] const Type& elementType() const noexcept { return *element_type_; }
    [[nodiscard]] const std::vector<Dimension>& dimensions() const noexcept { return dimensions_; }
    [[nodiscard]] size_t rank() const noexcept { return dimensions_.size(); }

private:
    std::shared_ptr<const Type> element_type_;
    std::vector<Dimension> dimensions_;
};

class StructType final : public Type {
public:
    struct Field {
        std::string name;
        std::shared_ptr<const Type> type;
        std::optional<std::string> initialValue;
    };

    StructType(std::string name, std::vector<Field> fields)
        : name_(std::move(name)), fields_(std::move(fields)) {}

    [[nodiscard]] TypeCategory category() const noexcept override { return TypeCategory::Struct; }
    [[nodiscard]] std::string_view name() const noexcept override { return name_; }
    [[nodiscard]] size_t sizeInBits() const noexcept override;

    [[nodiscard]] const std::vector<Field>& fields() const noexcept { return fields_; }

private:
    std::string name_;
    std::vector<Field> fields_;
};

class EnumType final : public Type {
public:
    struct Enumerator {
        std::string name;
        std::optional<int64_t> value;
    };

    EnumType(std::string name, std::vector<Enumerator> enumerators)
        : name_(std::move(name)), enumerators_(std::move(enumerators)) {}

    [[nodiscard]] TypeCategory category() const noexcept override { return TypeCategory::Enum; }
    [[nodiscard]] std::string_view name() const noexcept override { return name_; }
    [[nodiscard]] size_t sizeInBits() const noexcept override { return 32; }

    [[nodiscard]] const std::vector<Enumerator>& enumerators() const noexcept { return enumerators_; }

private:
    std::string name_;
    std::vector<Enumerator> enumerators_;
};

inline std::string_view ElementaryType::name() const noexcept {
    switch (category_) {
        case TypeCategory::Bool: return "BOOL";
        case TypeCategory::Byte: return "BYTE";
        case TypeCategory::Word: return "WORD";
        case TypeCategory::DWord: return "DWORD";
        case TypeCategory::LWord: return "LWORD";
        case TypeCategory::SInt: return "SINT";
        case TypeCategory::Int: return "INT";
        case TypeCategory::DInt: return "DINT";
        case TypeCategory::LInt: return "LINT";
        case TypeCategory::USInt: return "USINT";
        case TypeCategory::UInt: return "UINT";
        case TypeCategory::UDInt: return "UDINT";
        case TypeCategory::ULInt: return "ULINT";
        case TypeCategory::Real: return "REAL";
        case TypeCategory::LReal: return "LREAL";
        case TypeCategory::Time: return "TIME";
        case TypeCategory::Date: return "DATE";
        case TypeCategory::TimeOfDay: return "TIME_OF_DAY";
        case TypeCategory::DateAndTime: return "DATE_AND_TIME";
        case TypeCategory::String: return "STRING";
        case TypeCategory::WString: return "WSTRING";
        case TypeCategory::Any: return "ANY";
        case TypeCategory::Invalid: return "INVALID";
        default: return "UNKNOWN";
    }
}

inline size_t ElementaryType::sizeInBits() const noexcept {
    switch (category_) {
        case TypeCategory::Bool: return 1;
        case TypeCategory::Byte: return 8;
        case TypeCategory::Word: return 16;
        case TypeCategory::DWord: return 32;
        case TypeCategory::LWord: return 64;
        case TypeCategory::SInt: return 8;
        case TypeCategory::Int: return 16;
        case TypeCategory::DInt: return 32;
        case TypeCategory::LInt: return 64;
        case TypeCategory::USInt: return 8;
        case TypeCategory::UInt: return 16;
        case TypeCategory::UDInt: return 32;
        case TypeCategory::ULInt: return 64;
        case TypeCategory::Real: return 32;
        case TypeCategory::LReal: return 64;
        default: return 0;
    }
}

inline size_t ArrayType::sizeInBits() const noexcept {
    size_t count = 1;
    for (const auto& dim : dimensions_) {
        count *= dim.size();
    }
    return element_type_ ? element_type_->sizeInBits() * count : 0;
}

inline size_t StructType::sizeInBits() const noexcept {
    size_t total = 0;
    for (const auto& field : fields_) {
        if (field.type) {
            total += field.type->sizeInBits();
        }
    }
    return total;
}

} // namespace matiec::types

#endif // MATIEC_TYPES_TYPE_HPP
