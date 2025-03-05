// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Juranek_GAM415 : ModuleRules
{
	public Juranek_GAM415(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
