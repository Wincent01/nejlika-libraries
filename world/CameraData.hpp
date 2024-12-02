#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"

namespace nejlika::world
{

class CameraData : public WorldSerialize
{
public:
    CameraData(nejlika::Reader& io, version version);

    CameraData();

    void Save(nejlika::Writer& io, version version) const override;

    const str16& GetNextPath() const;

    bool GetRotatePlayer() const;

    void SetNextPath(const str16& nextPath);

    void SetRotatePlayer(bool rotatePlayer);

    ~CameraData();

private:
    str16 m_NextPath;

    bool m_RotatePlayer;
};

}