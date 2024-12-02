#pragma once

namespace nejlika
{
class Context;

/**
 * @brief Represents a context extention.
 */
class ContextExtention
{
public:
    ContextExtention() = default;

    /**
     * @brief Clone this context extention.
     * 
     * @return A clone of this context extention.
     */
    virtual ContextExtention* Clone() const = 0;

    /**
     * @brief Initalize this context extention.
     * 
     * @param ctx The context to initalize.
     */
    virtual void Initalize(Context& ctx) = 0;

    /**
     * @brief Save this context extention. Invoked when the context is saved.
     * 
     * @param ctx The context to save.
     */
    virtual void Save(Context& ctx) = 0;

    /**
     * @brief Deinitialize this context extention.
     * 
     * @param ctx The context to deinitialize.
     */
    virtual void Deinitialize(Context& ctx) = 0;

    virtual ~ContextExtention() = default;
};

};

