#pragma once

#include <string>
#include <vector>
#include <iostream>

namespace nejlika
{

/**
 * @brief An error that can be generated by a type template.
 */
class TypeTemplateError
{
public:
    /**
     * @brief Construct a new TypeTemplateError object.
     * 
     * @param message The error message.
     */
    TypeTemplateError(const std::string& message);

    /**
     * @brief Construct a new TypeTemplateError object.
     * 
     * @param message The error message.
     * @param errors The child errors.
     */
    TypeTemplateError(const std::string& message, const std::vector<TypeTemplateError>& errors);
    
    /**
     * @brief Construct a new TypeTemplateError object.
     * 
     * @param message The error message.
     * @param error The child error.
     */
    TypeTemplateError(const std::string& message, const TypeTemplateError& error);

    /**
     * @brief Add a child error to this error.
     * 
     * @param error The child error.
     */
    void AddChildError(const TypeTemplateError& error);

    /**
     * @brief Add a vector of child errors to this error.
     * 
     * @param errors The child errors.
     */
    void AddChildErrors(const std::vector<TypeTemplateError>& errors);

    /**
     * @brief Get the error message.
     * 
     * @return The error message.
     */
    const std::string& GetMessage() const;

    /**
     * @brief Get the child errors.
     * 
     * @return The child errors.
     */
    const std::vector<TypeTemplateError>& GetChildErrors() const;

    /**
     * @brief Print the error message and all child errors.
     * 
     * @param indent The indentation level.
     * @param output The output stream.
     */
    void Print(int32_t indent, std::ostream& output) const;

    bool IsSuccess() const;

    static const TypeTemplateError Success;

private:
    std::string m_Message;
    std::vector<TypeTemplateError> m_Chilren;
};

}