#pragma once

/**
 * @brief Enum defining the different types of objects in the game.
 * Used for type identification and collision handling.
 */
enum ObjectTypes{
	ACTOR,       ///< Base actor type
	OBJECT,      ///< Standard object (e.g., walls/obstacles)
	PLATFORM,    ///< Platform object (can be jumped on)
	PLAYER,      ///< Player character
	COLLECTIBLE, ///< Collectible item (e.g., coin)
	SPIKE
};