#include "PokemonRom.h"

//版本名字
std::vector<std::string>	rgszRomName =
{
    "红宝石（日文版）",	// ruby jp
    "蓝宝石（日文版）",	// sapphire jp
    "红宝石（英文版）",	// ruby en
    "蓝宝石（英文版）",	// sapphire en
    "火红（日文版）",	// fire jp
    "叶绿（日文版）",	// leaf jp
    "火红（英文版）",	// fire en
    "叶绿（英文版）",	// leaf en
    "绿宝石（日文版）",	// emerald jp
    "绿宝石（英文版）",	// emerald en
};

//每个游戏版本中物品的数量
std::vector<uint16_t> wItemCounts =
{
	0x15D,		// ruby jp
	0x15D,		// sapphire jp
	0x15D,		// ruby en
	0x15D,		// sapphire en
	0x177,		// fire jp
	0x177,		// leaf jp
	0x177,		// fire en
	0x177,		// leaf en
	0x179,		// emerald jp
	0x179,		// emerald en
};

//每个游戏版本中可能的宝可梦遭遇数量
std::vector<uint32_t> dwEncCounts =
{
	0x61,		// ruby jp
	0x61,		// sapphire jp
	0x61,		// ruby en
	0x61,		// sapphire en
	0x84,		// fire jp
	0x84,		// leaf jp
	0x84,		// fire en
	0x84,		// leaf en
	0x7C,		// emerald jp
	0x7C,		// emerald en
};


//不同类型的遭遇表条目的数量。每个元素代表一种不同类型的宝可梦遭遇（如陆地、海洋、石头等）。
std::vector<uint32_t> dwEncListEntryCounts =
{
	ENC_LAND_ENTRY_COUNT,	// enc_land
	ENC_WATER_ENTRY_COUNT,	// enc_water
	ENC_STONE_ENTRY_COUNT,	// enc_stone
	ENC_FISH_ENTRY_COUNT,	// enc_fish
};


//每个游戏版本中遭遇表的大小。每个元素是一个 32 位无符号整数，表示不同版本游戏中的遭遇表大小。
std::vector<uint32_t> dwEncListSizes =
{
	0x1F14,		// ruby jp
	0x1F14,		// sapphire jp
	0x1F14,		// ruby en
	0x1F14,		// sapphire en
	0x2918,		// fire jp
	0x2918,		// leaf jp
	0x2918,		// fire en
	0x2918,		// leaf en
	0x2564,		// emerald jp
	0x2564,		// emerald en
};

