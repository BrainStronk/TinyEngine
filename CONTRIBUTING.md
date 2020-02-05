# Contributing 

Anyone can commit code into the TinyEngine code base if they go through the right process. 

## License 
TinyEngine is CC0, so before you merge your code into the engine be sure that you're okay with your code being released into the Public Domain.

## Pull Request workflow
1. Create a new branch for the feature/bug you are working on. There should be a Github issue related to this.
2. Do the work to fix X bug or add X feature.
3. Open a Pull Request to merge your code into the master branch.
4. Wait for CI, and make sure it passes.  
5. Get your PR reviewed. Once it is approved the code will be merged into master

## Style Guide

Snake case for types, structs, and classes:
`struct my_awesome_struct {}; `

Functions and methods should be pascal case:
`
void MyFunction(int X)
{
}
`

Prefer project types over build in C types. So instead of `unsigned int` use `u32`.
Always use `b32`, instead of `bool`.
Braces should always go on a new line when introducing scope, this is **not** okay:
```
// I didn't read the style guide look at me 
void ThisIsTheBestFuncEver(int X) { 
}
```

### General Programming Practices:
- Keep the code base simple and make abstractions where it makes sense
- Use normal modern-ish api's that are used in games shipping today
- Use libraries where they make sense stb_image, stb_ttf, handmade math, etc
- Define a very clear line between the engine and platform layer, so that the engine could be easily ported
- Extensively test your code before you open a PR (I know this should be a given, but some people don't)
- If you are introducing a new system, or something larger to the code base be sure to run it through a profiler. 
