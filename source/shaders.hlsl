struct vs_out
{
    float4 Position : SV_POSITION;
    float4 Color : COLOR;
};

float4
PS(vs_out Input) : SV_TARGET
{
    return(Input.Color);
}

float4 
ConvertScreenspaceToViewspace(float4 Position : POSITION, int ScreenWidth, int ScreenHeight)
{
    
}

vs_out
VS(float4 Position : POSITION, float4 Color : COLOR)
{
    vs_out Output;
    Output.Position = Position;
    Output.Color = Color;
    return(Output);
}