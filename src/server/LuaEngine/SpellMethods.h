#ifndef SPELLMETHODS_H
#define SPELLMETHODS_H

class LuaSpell
{
public:
	// :GetUnitType()
	static int GetUnitType(lua_State* L, Spell* spell)
	{
		if (!spell)
			return 0;

		lua_pushstring(L, "Spell");
		return 1;
	}

    // GetCaster()
    static int GetCaster(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        Eluna::get()->PushUnit(L, spell->GetCaster());
        return 1;
    }

    // GetCastTime()
    static int GetCastTime(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        Eluna::get()->PushInteger(L, spell->GetCastTime());
        return 1;
    }

    // GetId()
    static int GetId(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        Eluna::get()->PushUnsigned(L, spell->GetSpellInfo()->Id);
        return 1;
    }

	// GetPowerCost()
	static int GetPowerCost(lua_State* L, Spell* spell)
	{
		if (!spell)
			return 0;

		Eluna::get()->PushInteger(L, spell->GetPowerCost());
		return 1;
	}

	// GetDuration()
	static int GetDuration(lua_State* L, Spell* spell)
	{
		if (!spell)
			return 0;

		Eluna::get()->PushInteger(L, spell->GetSpellInfo()->GetDuration());
		return 1;
	}

	// Cast(skipCheck)
	static int Cast(lua_State* L, Spell* spell)
	{
		if (!spell)
			return 0;

		bool skipCheck = lua_toboolean(L, 1);
		spell->cast(skipCheck);
		return 0;
	}

    // Cancel()
    static int cancel(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        spell->cancel();
        return 0;
    }

	// Finish()
	static int Finish(lua_State* L, Spell* spell)
	{
		if (!spell)
			return 0;

		spell->finish();
		return 0;
	}
};
#endif