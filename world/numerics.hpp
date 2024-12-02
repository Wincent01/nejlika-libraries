#pragma once

#include <string>
#include <cstdint>
#include <cmath>

using version = uint32_t;
using str16 = std::u16string;

#define TO_RADIANS(x) (x * 0.0174533f)
#define TO_DEGREES(x) (x * 57.2958f)

enum class PathBehavior : uint32_t
{
    Loop,
    Bounce,
    Once
};

enum class PathType : uint32_t
{
    NPC,
    Platform,
    Property,
    Camera,
    Spawner,
    BuildArea,
    Racing,
    Rail
};

enum class PropertyPathType : uint32_t
{
    Bounded,
    EntireZone,
    GeneratedRectangle
};

enum class PropertyType : uint32_t
{
    Premiere,
    Prize,
    Lup,
    Headspace
};

enum class NodeType : uint32_t
{
    EnvironmentObject = 0,
    Building = 1,
    Enemy = 2,
    Npc = 3,
    Rebuilder = 4,
    Spawned = 5,
    Cannon = 6,
    Bouncer = 7,
    Exhibit = 8,
    MovingPlatform = 9,
    Springpad = 10,
    Sound = 11,
    Particle = 12,
    GenericPlaceholder = 13,
    ErrorMarker = 14,
    PlayerStart = 15
};

enum class ObjectPropertyType : uint8_t
{
    String = 0, // utf16
    Integer = 1, // int32
    Float = 3, // float
    Double = 4, // double
    UnsignedInteger = 5, // uint32
    Boolean = 7, // bool
    Long = 8, // int64
    Blob = 13 // uint8[] / utf8
};

/**
 * @brief Vector 3.
 */
struct vector3
{
    float x = 0;
    float y = 0;
    float z = 0;

    // Constructors
    vector3() = default;

    vector3(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    // Comparison operators
    bool operator==(const vector3& other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const vector3& other) const
    {
        return !(*this == other);
    }

    // Arithmetic operators
    vector3 operator+(const vector3& other) const
    {
        return { x + other.x, y + other.y, z + other.z };
    }

    vector3 operator-(const vector3& other) const
    {
        return { x - other.x, y - other.y, z - other.z };
    }

    vector3 operator*(const vector3& other) const
    {
        return { x * other.x, y * other.y, z * other.z };
    }

    vector3 operator/(const vector3& other) const
    {
        return { x / other.x, y / other.y, z / other.z };
    }

    vector3 operator+(float scalar) const
    {
        return { x + scalar, y + scalar, z + scalar };
    }

    vector3 operator-(float scalar) const
    {
        return { x - scalar, y - scalar, z - scalar };
    }

    vector3 operator*(float scalar) const
    {
        return { x * scalar, y * scalar, z * scalar };
    }

    vector3 operator/(float scalar) const
    {
        return { x / scalar, y / scalar, z / scalar };
    }

    vector3& operator+=(const vector3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;

        return *this;
    }

    vector3& operator-=(const vector3& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;

        return *this;
    }

    vector3& operator*=(const vector3& other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;

        return *this;
    }

    vector3& operator/=(const vector3& other)
    {
        x /= other.x;
        y /= other.y;
        z /= other.z;

        return *this;
    }

    vector3& operator+=(float scalar)
    {
        x += scalar;
        y += scalar;
        z += scalar;

        return *this;
    }

    vector3& operator-=(float scalar)
    {
        x -= scalar;
        y -= scalar;
        z -= scalar;

        return *this;
    }

    vector3& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;

        return *this;
    }

    vector3& operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;

        return *this;
    }

    // Unary operators
    vector3 operator-() const
    {
        return { -x, -y, -z };
    }

    // Dot product
    float dot(const vector3& other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    // Cross product
    vector3 cross(const vector3& other) const
    {
        return { y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x };
    }

    // Magnitude
    float magnitude() const
    {
        return sqrtf(x * x + y * y + z * z);
    }

    // Normalize
    vector3 normalize() const
    {
        float mag = magnitude();

        if (mag == 0)
        {
            return { 0, 0, 0 };
        }

        return { x / mag, y / mag, z / mag };
    }

    // Distance
    float distance(const vector3& other) const
    {
        return (*this - other).magnitude();
    }

    float distanceSquared(const vector3& other) const
    {
        return (*this - other).dot(*this - other);
    }
};

/**
 * @brief Color (RGB).
 */
struct color
{
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
};

/**
 * @brief Color (RGBA).
 */
struct color4
{
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    uint8_t a = 0;
};

/**
 * @brief Vector 4.
 */
struct vector4
{
    float w = 0;
    float x = 0;
    float y = 0;
    float z = 0;

    // Constructors
    vector4() = default;

    vector4(float w, float x, float y, float z)
        : w(w), x(x), y(y), z(z)
    {
    }

    // Comparison operators
    bool operator==(const vector4& other) const
    {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    bool operator!=(const vector4& other) const
    {
        return !(*this == other);
    }

    // Quaternion operators
    vector4 operator*(const vector4& q) const {
        // Quaternion multiplication
        const auto w = this->w * q.w - this->x * q.x - this->y * q.y - this->z * q.z;
        const auto x = this->w * q.x + this->x * q.w + this->y * q.z - this->z * q.y;
        const auto y = this->w * q.y - this->x * q.z + this->y * q.w + this->z * q.x;
        const auto z = this->w * q.z + this->x * q.y - this->y * q.x + this->z * q.w;

        return vector4(w, x, y, z);
    }

    static vector4 fromAxisAngle(const vector3& axis, float angle)
    {
        float halfAngle = angle * 0.5f;
        float s = sinf(halfAngle);

        return vector4(cosf(halfAngle), axis.x * s, axis.y * s, axis.z * s);
    }

    static vector4 fromEulerAngles(vector3 angles)
    {
        // Convert to radians
        angles.x = angles.x * 0.0174533f;
        angles.y = angles.y * 0.0174533f;
        angles.z = angles.z * 0.0174533f;
        
        float c1 = cosf(angles.y / 2);
        float s1 = sinf(angles.y / 2);
        float c2 = cosf(angles.z / 2);
        float s2 = sinf(angles.z / 2);
        float c3 = cosf(angles.x / 2);
        float s3 = sinf(angles.x / 2);
        float c1c2 = c1 * c2;
        float s1s2 = s1 * s2;

        return vector4(
            c1c2 * c3 - s1s2 * s3,
            c1c2 * s3 + s1s2 * c3,
            s1 * c2 * c3 + c1 * s2 * s3,
            c1 * s2 * c3 - s1 * c2 * s3
        );
    }
};

struct transform
{
    vector3 position;
    vector4 rotation;
    float scale;

    // Constructors
    transform() = default;

    transform(const vector3& position, const vector4& rotation, const float& scale)
        : position(position), rotation(rotation), scale(scale)
    {
    }

    // Rotates the transform by the given quaternion
    // Affects both position and rotation
    transform rotate(const vector4& q) const
    {
        vector4 pointVector = vector4(0, position.x, position.y, position.z);
        vector4 inverse = vector4(q.w, -q.x, -q.y, -q.z);

        // Hamilton product
        vector4 result = (q * pointVector) * inverse;

        return transform(vector3(result.x, result.y, result.z), rotation * q, scale);
    }
};

enum class ObjectFlags : uint32_t {
    Persistent = 1 << 0,
    Client = 1 << 14,
    Spawned = 1 << 26,
    Character = 1 << 28
};

struct objectid {
    uint32_t id;
    struct {
        bool persistent : 1;
        int32_t unknown : 13;
        bool client : 1;
        int32_t unknown2 : 10;
        bool spawned : 1;
        int32_t unknown3 : 2;
        bool character : 1;
        int32_t unknown4 : 3;
    } flags;
};

inline std::string u16string_to_string(const std::u16string& u16str) {
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
    return convert.to_bytes(u16str);
}

inline std::u16string string_to_u16string(const std::string& str) {
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
    return convert.from_bytes(str);
}
