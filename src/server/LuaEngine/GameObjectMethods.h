#ifndef GAMEOBJECTMETHODS_H
#define GAMEOBJECTMETHODS_H

class LuaGameObject
{
public:

    // GetUnitType()
    static int GetUnitType(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushString(L, "GameObject");
        return 1;
    }

    // GetGUID()
    static int GetGUID(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushGUID(L, go->GetGUID());
        return 1;
    }

    // CastSpellOnTarget(target, spellid)
    static int CastSpellOnTarget(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint32 spell = luaL_checkunsigned(L, 1);
        Unit* target = Eluna::get()->CHECK_UNIT(L, 2);

        if (target)
            go->CastSpell(target, spell);
        return 0;
    }

    // GetX()
    static int GetX(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetPositionX());
        return 1;
    }

    // GetY()
    static int GetY(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetPositionY());
        return 1;
    }

    // GetZ()
    static int GetZ(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetPositionZ());
        return 1;
    }

    // GetO()
    static int GetO(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetOrientation());
        return 1;
    }

    // GetLocation()
    static int GetLocation(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetPositionX());
        Eluna::get()->PushFloat(L, go->GetPositionY());
        Eluna::get()->PushFloat(L, go->GetPositionZ());
        Eluna::get()->PushFloat(L, go->GetOrientation());

        return 4;
    }

    // GetMapId()
    static int GetMapId(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetMapId());
        return 1;
    }

    // GetZoneId()
    static int GetZoneId(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetZoneId());
        return 1;
    }

    // GetAreaId()
    static int GetAreaId(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetAreaId());
        return 1;
    }

    // GetName()
    static int GetName(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushString(L, go->GetName().c_str());
        return 1;
    }

    // GetEntry()
    static int GetEntry(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushUnsigned(L, go->GetEntry());
        return 1;
    }

    // SummonCreature(entry, x, y, z, o, despawntime)
    static int SummonCreature(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint32 entry = luaL_checkunsigned(L, 1);
        float x = luaL_checknumber(L, 2);
        float y = luaL_checknumber(L, 3);
        float z = luaL_checknumber(L, 4);
        float o = luaL_checknumber(L, 5);
        uint32 despawn = luaL_optunsigned(L, 6, 0);

        TempSummonType summontype;
        if (despawn)
            summontype = TEMPSUMMON_TIMED_OR_DEAD_DESPAWN;
        else
            summontype = TEMPSUMMON_MANUAL_DESPAWN;
        Eluna::get()->PushUnit(L, go->SummonCreature(entry, x, y, z, o, summontype, despawn));
        return 1;
    }

    // GetDisplayId()
    static int GetDisplayId(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushUnsigned(L, go->GetDisplayId());
        return 1;
    }

    // GetScale()
    static int GetScale(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetObjectSize());
        return 1;
    }

    // IsInWorld()
    static int IsInWorld(lua_State* L, GameObject* go)
    {
        if (!go)
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, go->IsInWorld());
        return 1;
    }

    // HasQuest(questId)
    static int HasQuest(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            Eluna::get()->PushBoolean(L, false);
        else
        {
            uint32 questId = luaL_checkunsigned(L, 1);
            Eluna::get()->PushBoolean(L, go->hasQuest(questId));
        }
        return 1;
    }

    // IsTransport()
    static int IsTransport(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, go->IsTransport());
        return 1;
    }

    // IsDestructible()
    static int IsDestructible(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, go->IsDestructibleBuilding());
        return 1;
    }

    // IsActive()
    static int IsActive(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, go->isActiveObject());
        return 1;
    }

    // Move(x, y, z, o)
    static int Move(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        float X = luaL_checknumber(L, 1);
        float Y = luaL_checknumber(L, 2);
        float Z = luaL_checknumber(L, 3);
        float O = luaL_checknumber(L, 4);

        go->Relocate(X, Y, Z, O);
        return 0;
    }

    // SetScale(scale)
    static int SetScale(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        float scale = luaL_checknumber(L, 1);

        go->SetObjectScale(scale);
        return 0;
    }

    // RegisterEvent(function, delay, calls)
    static int RegisterEvent(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint32 delay = luaL_checkunsigned(L, 2);
        uint32 repeats = luaL_checkunsigned(L, 3);
        Eluna::LuaGameObjectScript::LuaGameObjectAI* luaAI = sLuaGameObjectScript->GetAI(go);
        if (!luaAI)
        {
            luaL_error(L, "GameObject has no registered gameobject events, please register one before using RegisterEvent");
            return 0;
        }
        if (!strcmp(luaL_typename(L, 1), "function") || delay > 0)
        {
            lua_settop(L, 1);
            int functionRef = lua_ref(L, true);
            luaAI->LuaEventCreate(functionRef, delay, repeats);
            Eluna::get()->PushInteger(L, functionRef);
        }
        else
            return 0;
        return 1;

    }

    // RemoveEventByID(eventID)
    static int RemoveEventByID(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        int eventID = luaL_checkinteger(L, 1);
        Eluna::LuaGameObjectScript::LuaGameObjectAI* luaAI = sLuaGameObjectScript->GetAI(go);

        if (luaAI)
            luaAI->LuaEventCancel(eventID);
        return 0;
    }

    // RemoveEvents()
    static int RemoveEvents(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Eluna::LuaGameObjectScript::LuaGameObjectAI* luaAI = sLuaGameObjectScript->GetAI(go);
        if (luaAI)
            luaAI->LuaEventsReset();
        return 0;
    }

    static int GetInt32Value(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);

        Eluna::get()->PushInteger(L, go->GetInt32Value(index));
        return 1;
    }

    static int GetUInt32Value(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);

        Eluna::get()->PushUnsigned(L, go->GetUInt32Value(index));
        return 1;
    }

    static int GetFloatValue(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);

        Eluna::get()->PushFloat(L, go->GetFloatValue(index));
        return 1;
    }

    static int GetByteValue(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);

        Eluna::get()->PushUnsigned(L, go->GetByteValue(index, offset));
        return 1;
    }

    static int GetUInt16Value(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);

        Eluna::get()->PushUnsigned(L, go->GetUInt16Value(index, offset));
        return 1;
    }

    static int SetInt32Value(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        int32 value = luaL_checkinteger(L, 2);

        go->SetInt32Value(index, value);
        return 0;
    }

    static int SetUInt32Value(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        uint32 value = luaL_checkunsigned(L, 2);

        go->SetUInt32Value(index, value);
        return 0;
    }

    static int UpdateUInt32Value(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        uint32 value = luaL_checkunsigned(L, 2);

        go->UpdateUInt32Value(index, value);
        return 0;
    }

    static int SetFloatValue(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        float value = luaL_checknumber(L, 2);

        go->SetFloatValue(index, value);
        return 0;
    }

    static int SetByteValue(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        uint8 value = luaL_checkunsigned(L, 3);

        go->SetByteValue(index, offset, value);
        return 0;
    }

    static int SetUInt16Value(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        uint16 value = luaL_checkunsigned(L, 3);

        go->SetUInt16Value(index, offset, value);
        return 0;
    }

    static int SetInt16Value(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        int16 value = luaL_checkinteger(L, 3);

        go->SetInt16Value(index, offset, value);
        return 0;
    }
};

#endif