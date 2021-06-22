// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Test619 : ModuleRules
{
	public Test619(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
