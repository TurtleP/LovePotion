#include "revolutejoint/wrap_revolutejoint.h"
#include "joint/wrap_joint.h"

using namespace love;

RevoluteJoint* Wrap_RevoluteJoint::CheckRevoluteJoint(lua_State* L, int index)
{
    RevoluteJoint* joint = Luax::CheckType<RevoluteJoint>(L, index);

    if (!joint->IsValid())
        luaL_error(L, "Attempt to use destroyed joint!");

    return joint;
}

int Wrap_RevoluteJoint::GetJointAngle(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);

    lua_pushnumber(L, self->GetJointAngle());

    return 1;
}

int Wrap_RevoluteJoint::GetJointSpeed(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);

    lua_pushnumber(L, self->GetJointSpeed());

    return 1;
}

int Wrap_RevoluteJoint::SetMotorEnabled(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);
    bool enabled        = Luax::CheckBoolean(L, 2);

    self->SetMotorEnabled(enabled);

    return 0;
}

int Wrap_RevoluteJoint::IsMotorEnabled(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);

    Luax::PushBoolean(L, self->IsMotorEnabled());

    return 1;
}

int Wrap_RevoluteJoint::SetMaxMotorTorque(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);
    float torque        = luaL_checknumber(L, 2);

    self->SetMaxMotorTorque(torque);

    return 0;
}

int Wrap_RevoluteJoint::SetMotorSpeed(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);
    float speed         = luaL_checknumber(L, 2);

    self->SetMotorSpeed(speed);

    return 0;
}

int Wrap_RevoluteJoint::GetMotorSpeed(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);

    lua_pushnumber(L, self->GetMotorSpeed());

    return 1;
}

int Wrap_RevoluteJoint::GetMotorTorque(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);
    float invDt         = luaL_checknumber(L, 2);

    lua_pushnumber(L, self->GetMotorTorque(invDt));

    return 1;
}

int Wrap_RevoluteJoint::GetMaxMotorTorque(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);

    lua_pushnumber(L, self->GetMaxMotorTorque());

    return 1;
}

int Wrap_RevoluteJoint::SetLimitsEnabled(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);
    bool enabled        = Luax::CheckBoolean(L, 2);

    self->SetLimitsEnabled(enabled);

    return 0;
}

int Wrap_RevoluteJoint::AreLimitsEnabled(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);

    Luax::PushBoolean(L, self->AreLimitsEnabled());

    return 1;
}

int Wrap_RevoluteJoint::SetUpperLimit(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);
    float limit         = luaL_checknumber(L, 2);

    Luax::CatchException(L, [&]() { self->SetUpperLimit(limit); });

    return 0;
}

int Wrap_RevoluteJoint::SetLowerLimit(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);
    float limit         = luaL_checknumber(L, 2);

    Luax::CatchException(L, [&]() { self->SetLowerLimit(limit); });

    return 0;
}

int Wrap_RevoluteJoint::SetLimits(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);

    float lower = luaL_checknumber(L, 2);
    float upper = luaL_checknumber(L, 3);

    Luax::CatchException(L, [&]() { self->SetLimits(lower, upper); });

    return 0;
}

int Wrap_RevoluteJoint::GetLowerLimit(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);

    lua_pushnumber(L, self->GetLowerLimit());

    return 1;
}

int Wrap_RevoluteJoint::GetUpperLimit(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);

    lua_pushnumber(L, self->GetUpperLimit());

    return 1;
}

int Wrap_RevoluteJoint::GetLimits(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);
    lua_remove(L, 1);

    return self->GetLimits(L);
}

int Wrap_RevoluteJoint::GetReferenceAngle(lua_State* L)
{
    RevoluteJoint* self = Wrap_RevoluteJoint::CheckRevoluteJoint(L, 1);

    lua_pushnumber(L, self->GetReferenceAngle());

    return 1;
}

int Wrap_RevoluteJoint::Register(lua_State* L)
{
    luaL_Reg funcs[] = { { "getJointAngle", GetJointAngle },
                         { "getJointSpeed", GetJointSpeed },
                         { "setMotorEnabled", SetMotorEnabled },
                         { "isMotorEnabled", IsMotorEnabled },
                         { "setMaxMotorTorque", SetMaxMotorTorque },
                         { "setMotorSpeed", SetMotorSpeed },
                         { "getMotorSpeed", GetMotorSpeed },
                         { "getMotorTorque", GetMotorTorque },
                         { "getMaxMotorTorque", GetMaxMotorTorque },
                         { "setLimitsEnabled", SetLimitsEnabled },
                         { "areLimitsEnabled", AreLimitsEnabled },
                         { "setUpperLimit", SetUpperLimit },
                         { "setLowerLimit", SetLowerLimit },
                         { "setLimits", SetLimits },
                         { "getLowerLimit", GetLowerLimit },
                         { "getUpperLimit", GetUpperLimit },
                         { "getLimits", GetLimits },
                         { "getReferenceAngle", GetReferenceAngle },
                         { 0, 0 } };

    return Luax::RegisterType(L, &RevoluteJoint::type, Wrap_Joint::functions, funcs, nullptr);
}
