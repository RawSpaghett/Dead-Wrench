// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Dead_Wrench : ModuleRules
{
	public Dead_Wrench(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
