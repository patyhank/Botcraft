#pragma once

namespace Botcraft
{
#if PROTOCOL_VERSION < 719
    enum class Dimension
    {
        None = -2,
        Nether,
        Overworld,
        End
    };
#endif

    enum class GameMode
    {
        None = -1,
        Survival,
        Creative,
        Adventure,
        Spectator
    };

    enum class Difficulty
    {
        None = -1,
        Peaceful,
        Easy,
        Normal,
        Hard
    };

    enum class ChatMode
    {
        Enabled,
        CommandsOnly,
        Hidden
    };

    enum class Hand
    {
        Left,
        Right
    };

    enum class TintType
    {
        None,
        Water,
        Redstone,
        Grass,
        Leaves
    };

    enum class Orientation
    {
        None = -1,
        Bottom = 0, // y = -1
        North,      // z = -1
        West,       // x = -1
        East,       // x = 1
        South,      // z = 1
        Top         // y = 1
    };

    enum class PlayerDiggingStatus
    {
        StartDigging = 0,
        CancelDigging,
        FinishDigging,
        DropItemStack,
        DropItem,
        ShootArrow_FinishEating,
        SwapItemHand
    };

    enum class PlayerDiggingFace
    {
        Bottom = 0, // -Y
        Top,        // +Y
        North,      // -Z
        South,      // +Z
        West,       // -X
        East        // +X
    };
} // Botcraft