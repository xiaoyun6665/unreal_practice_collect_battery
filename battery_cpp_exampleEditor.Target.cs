// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class battery_cpp_exampleEditorTarget : TargetRules
{
	public battery_cpp_exampleEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("battery_cpp_example");
	}
}
