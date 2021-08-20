#pragma once

class Settings
{
public:
	static Settings* GetSingleton();

	void LoadSettings();

	bool FastTravelDisabled;
	bool FlyingMountCruiseEnabled;
};
