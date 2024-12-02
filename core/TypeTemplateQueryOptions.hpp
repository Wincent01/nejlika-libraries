#pragma once

/**
 * @brief Options for querying type templates for values.
 */
enum class TypeTemplateQueryOptions
{
    /**
     * @brief No options, shouldn't cascade generation of runtime information.
     */
    None = 0 << 0,

    /**
     * @brief Seek to include identifiers, will cause the query to generate runtime information.
     */
    Identifiers = 1 << 0,

    /**
     * @brief Seek to include full information, will cause the query to generate runtime information.
     */
    Full = 1 << 1
};