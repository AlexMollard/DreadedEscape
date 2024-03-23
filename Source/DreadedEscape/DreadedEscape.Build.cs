// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DreadedEscape : ModuleRules
{
	public DreadedEscape(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
