// Copyright 2022 (C) Jakub Mieczkowski

using UnrealBuildTool;

public class FactManager : ModuleRules
{
	public FactManager(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new string[]{ "Core" });
			
		
		PrivateDependencyModuleNames.AddRange(new string[]{ "CoreUObject", "Engine" });
		
	}
}
