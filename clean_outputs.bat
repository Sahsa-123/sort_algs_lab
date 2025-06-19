@echo off
echo file cleaning

for %%d in (
    inputs
    outputs_bubble
    outputs_heap
    outputs_shaker
    outputs_std
) do (
    if exist %%d (
        echo dir clean %%d
        del /Q /F %%d\*
    ) else (
        echo dir %%d not found
    )
)

echo ready.
