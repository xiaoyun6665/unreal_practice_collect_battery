// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class battery_cpp_exampleTarget : TargetRules
{
	public battery_cpp_exampleTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("battery_cpp_example");
	}
}
