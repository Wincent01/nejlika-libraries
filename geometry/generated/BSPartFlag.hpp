#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Editor flags for the Body Partitions. 
 *         
 */
enum BSPartFlag : ushort
{
    /**
     * Visible in Editor
     */
    PF_EDITOR_VISIBLE = 0,
    /**
     * Start a new shared boneset.  It is expected this BoneSet and the following sets in the Skin Partition will have the same bones.
     */
    PF_START_NET_BONESET = 8,
};

}
