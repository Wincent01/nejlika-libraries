#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Specifies the time when an application must syncronize for some reason.
 *         
 */
enum SyncPoint : ushort
{
    /**
     * Value used when no specific sync point is desired.
     */
    SYNC_ANY = 32768,
    /**
     * Synchronize when an object is updated.
     */
    SYNC_UPDATE = 32784,
    /**
     * Synchronize when an entire scene graph has been updated.
     */
    SYNC_POST_UPDATE = 32800,
    /**
     * Synchronize when an object is determined to be potentially visible.
     */
    SYNC_VISIBLE = 32816,
    /**
     * Synchronize when an object is rendered.
     */
    SYNC_RENDER = 32832,
    /**
     * Synchronize when a physics simulation step is about to begin.
     */
    SYNC_PHYSICS_SIMULATE = 32848,
    /**
     * Synchronize when a physics simulation step has produced results.
     */
    SYNC_PHYSICS_COMPLETED = 32864,
    /**
     * Syncronize after all data necessary to calculate reflections is ready.
     */
    SYNC_REFLECTIONS = 32880,
};

}
