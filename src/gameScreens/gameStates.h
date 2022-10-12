#pragma once



enum class GameStates{InitialAnimation = -1,Menu,Game,Rules,Credits,Exit};
void setGameState(GameStates newState);
