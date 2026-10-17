#include <openvr.h>
#include <iostream>
#include <limits.h>

int main(int argc, char const** argv)
{
	if (argc > 2)
	{
		std::cerr << "Too many arguments (expected 0 or 1)." << std::endl;
		return 1;
	}

	vr::EVRInitError initError = vr::VRInitError_None;
	vr::IVRSystem* vrSystem = vr::VR_Init(&initError, vr::VRApplication_Utility);

	if (initError != vr::VRInitError_None)
	{
		std::cerr << "Failed: VRInit Failed: " << vr::VR_GetVRInitErrorAsEnglishDescription(initError) << std::endl;
		return 1;
	}

	vr::IVRSettings* vrSettings = vr::VRSettings();

	if (vrSettings == nullptr)
	{
		std::cerr << "Failed: Failed to access VR settings." << std::endl;
		vr::VR_Shutdown();
		return 1;
	}

	vr::EVRSettingsError error = vr::VRSettingsError_None;

	if (argc == 2)
	{
		char const* passedPath = argv[1];
		char absolutePath[PATH_MAX];

		if (realpath(passedPath,absolutePath) == nullptr)
		{
			std::cerr << "Failed: Could not locate path: " << passedPath << std::endl;
			vr::VR_Shutdown();
			return 1;
		}

		vrSettings->SetString(vr::k_pch_SteamVR_Section, vr::k_pch_SteamVR_Background_String, argv[1], &error);

		if (error != vr::VRSettingsError_None)
		{
			std::cerr << "Failed: Failed to set background setting: " << vrSettings->GetSettingsErrorNameFromEnum(error) << std::endl;
			vr::VR_Shutdown();
			return 1;
		}
	}

	int mode = vrSettings->GetInt32(vr::k_pch_SteamVR_Section, "environmentMode", &error);
	if (error != vr::VRSettingsError_None)
	{
		std::cerr << "Warning: Unable to read environment mode setting; this image may not be used until environment style is changed." << std::endl;
		error = vr::VRSettingsError_None;
	}
	else if (mode != 0)
	{
		std::cerr << "Warning: Play Area environment style is not set to 'image'; this image will not be used until environment style is changed." << std::endl;
	}

	char background[PATH_MAX];
	vrSettings->GetString(vr::k_pch_SteamVR_Section, vr::k_pch_SteamVR_Background_String, (char*)&background, PATH_MAX, &error);

	if (error != vr::VRSettingsError_None)
	{
		std::cerr << "Failed: Failed to read background setting: " << vrSettings->GetSettingsErrorNameFromEnum(error) << std::endl;
		vr::VR_Shutdown();
		return 1;
	}

	std::cout << background << std::endl;

	vr::VR_Shutdown();
	return 0;
}
