/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 */

#ifndef MATIEC_TYPES_TYPE_REGISTRY_HPP
#define MATIEC_TYPES_TYPE_REGISTRY_HPP

#include <cctype>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>

#include "matiec/types/type.hpp"

namespace matiec::types {

class TypeRegistry {
public:
    TypeRegistry();

    [[nodiscard]] std::shared_ptr<const Type> getBool() const noexcept { return bool_type_; }
    [[nodiscard]] std::shared_ptr<const Type> getInt() const noexcept { return int_type_; }
    [[nodiscard]] std::shared_ptr<const Type> getDInt() const noexcept { return dint_type_; }
    [[nodiscard]] std::shared_ptr<const Type> getReal() const noexcept { return real_type_; }
    [[nodiscard]] std::shared_ptr<const Type> getString() const noexcept { return string_type_; }
    [[nodiscard]] std::shared_ptr<const Type> getTime() const noexcept { return time_type_; }

    [[nodiscard]] std::shared_ptr<const Type> findType(std::string_view name) const;

    void registerType(std::string name, std::shared_ptr<const Type> type);

    [[nodiscard]] std::shared_ptr<const ArrayType> createArrayType(
        std::shared_ptr<const Type> element_type,
        std::vector<ArrayType::Dimension> dims);

    [[nodiscard]] std::shared_ptr<const StructType> createStructType(
        std::string name,
        std::vector<StructType::Field> fields);

    [[nodiscard]] std::shared_ptr<const EnumType> createEnumType(
        std::string name,
        std::vector<EnumType::Enumerator> enumerators);

private:
    static std::string normalize(std::string_view name);

    std::unordered_map<std::string, std::shared_ptr<const Type>> types_;
    std::shared_ptr<const Type> bool_type_;
    std::shared_ptr<const Type> int_type_;
    std::shared_ptr<const Type> dint_type_;
    std::shared_ptr<const Type> real_type_;
    std::shared_ptr<const Type> string_type_;
    std::shared_ptr<const Type> time_type_;
};

inline std::string TypeRegistry::normalize(std::string_view name) {
    std::string out;
    out.reserve(name.size());
    for (char ch : name) {
        out.push_back(static_cast<char>(std::toupper(static_cast<unsigned char>(ch))));
    }
    return out;
}

inline TypeRegistry::TypeRegistry() {
    bool_type_ = std::make_shared<ElementaryType>(TypeCategory::Bool);
    int_type_ = std::make_shared<ElementaryType>(TypeCategory::Int);
    dint_type_ = std::make_shared<ElementaryType>(TypeCategory::DInt);
    real_type_ = std::make_shared<ElementaryType>(TypeCategory::Real);
    string_type_ = std::make_shared<ElementaryType>(TypeCategory::String);
    time_type_ = std::make_shared<ElementaryType>(TypeCategory::Time);

    types_.emplace(normalize("BOOL"), bool_type_);
    types_.emplace(normalize("BYTE"), std::make_shared<ElementaryType>(TypeCategory::Byte));
    types_.emplace(normalize("WORD"), std::make_shared<ElementaryType>(TypeCategory::Word));
    types_.emplace(normalize("DWORD"), std::make_shared<ElementaryType>(TypeCategory::DWord));
    types_.emplace(normalize("LWORD"), std::make_shared<ElementaryType>(TypeCategory::LWord));
    types_.emplace(normalize("SINT"), std::make_shared<ElementaryType>(TypeCategory::SInt));
    types_.emplace(normalize("INT"), int_type_);
    types_.emplace(normalize("DINT"), dint_type_);
    types_.emplace(normalize("LINT"), std::make_shared<ElementaryType>(TypeCategory::LInt));
    types_.emplace(normalize("USINT"), std::make_shared<ElementaryType>(TypeCategory::USInt));
    types_.emplace(normalize("UINT"), std::make_shared<ElementaryType>(TypeCategory::UInt));
    types_.emplace(normalize("UDINT"), std::make_shared<ElementaryType>(TypeCategory::UDInt));
    types_.emplace(normalize("ULINT"), std::make_shared<ElementaryType>(TypeCategory::ULInt));
    types_.emplace(normalize("REAL"), real_type_);
    types_.emplace(normalize("LREAL"), std::make_shared<ElementaryType>(TypeCategory::LReal));
    types_.emplace(normalize("TIME"), time_type_);
    types_.emplace(normalize("DATE"), std::make_shared<ElementaryType>(TypeCategory::Date));
    {
        auto tod_type = std::make_shared<ElementaryType>(TypeCategory::TimeOfDay);
        types_.emplace(normalize("TIME_OF_DAY"), tod_type);
        types_.emplace(normalize("TOD"), tod_type);
    }
    {
        auto dt_type = std::make_shared<ElementaryType>(TypeCategory::DateAndTime);
        types_.emplace(normalize("DATE_AND_TIME"), dt_type);
        types_.emplace(normalize("DT"), dt_type);
    }
    types_.emplace(normalize("STRING"), string_type_);
    types_.emplace(normalize("WSTRING"), std::make_shared<ElementaryType>(TypeCategory::WString));
    types_.emplace(normalize("ANY"), std::make_shared<ElementaryType>(TypeCategory::Any));
    types_.emplace(normalize("INVALID"), std::make_shared<ElementaryType>(TypeCategory::Invalid));
}

inline std::shared_ptr<const Type> TypeRegistry::findType(std::string_view name) const {
    const auto key = normalize(name);
    const auto it = types_.find(key);
    if (it == types_.end()) {
        return {};
    }
    return it->second;
}

inline void TypeRegistry::registerType(std::string name, std::shared_ptr<const Type> type) {
    if (!type) {
        return;
    }
    types_[normalize(name)] = std::move(type);
}

inline std::shared_ptr<const ArrayType> TypeRegistry::createArrayType(
    std::shared_ptr<const Type> element_type,
    std::vector<ArrayType::Dimension> dims) {
    auto type = std::make_shared<ArrayType>(std::move(element_type), std::move(dims));
    return type;
}

inline std::shared_ptr<const StructType> TypeRegistry::createStructType(
    std::string name,
    std::vector<StructType::Field> fields) {
    auto type = std::make_shared<StructType>(std::move(name), std::move(fields));
    return type;
}

inline std::shared_ptr<const EnumType> TypeRegistry::createEnumType(
    std::string name,
    std::vector<EnumType::Enumerator> enumerators) {
    auto type = std::make_shared<EnumType>(std::move(name), std::move(enumerators));
    return type;
}

} // namespace matiec::types

#endif // MATIEC_TYPES_TYPE_REGISTRY_HPP
