struct vs_out
{
    float4 Position : SV_POSITION;
    float4 Color : COLOR;
};

cbuffer constant_buffer
{
    int ScreenWidth;
    int ScreenHeight;
};

float4
PS(vs_out Input) : SV_TARGET
{
    return(Input.Color);
}

float4 
ConvertScreenspaceToViewspace(float4 Position : POSITION)
{
    float4 Result = {0, 0, 0, 0};

    Result.x = ((1.0f / ScreenWidth)  * Position.x) * 2.0f - 1.0f;
    Result.y = ((1.0f / ScreenHeight) * Position.y) * 2.0f - 1.0f;

    return(Result);
}

vs_out
VS(float4 Position : POSITION, float4 Color : COLOR)
{
    vs_out Output;

    // Position = ConvertScreenspaceToViewspace(Position);

    Output.Position = Position;
    Output.Color = Color;
    return(Output);
}