// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class battery_cpp_example : ModuleRules
{
	public battery_cpp_example(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
		PublicDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore", "UMG" });
	}
}
