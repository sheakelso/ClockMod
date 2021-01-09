# Builds a .zip file for loading with BMBF
& $PSScriptRoot/build.ps1

if ($?) {
    Compress-Archive -Path "./libs/arm64-v8a/libclockmod.so", "./libs/arm64-v8a/libbeatsaber-hook_0_8_4.so", "./bmbfmod.json" -DestinationPath "./clockmod_v0.1.0.zip" -Update
}
