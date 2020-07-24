#include "svpng.inc"

typedef struct
{
    float sd, emissive;
} Result;

Result unionOp(Result a, Result b) { return a.sd < b.sd ? a : b; }

Result scene(float x, float y)
{
    Result r1 = {circleSDF(x, y, 0.3f, 0.3f, 0.10f), 2.0f};
    Result r2 = {circleSDF(x, y, 0.3f, 0.7f, 0.05f), 0.8f};
    Result r3 = {circleSDF(x, y, 0.7f, 0.5f, 0.10f), 0.0f};
    return unionOp(unionOp(r1, r2), r3);
}

float trace(float ox, float oy, float dx, float dy)
{
    float t = 0.0f;
    for (int i = 0; i < MAX_STEP && t < MAX_DISTANCE; i++)
    {
        Result r = scene(ox + dx * t, oy + dy * t); // SDF
        if (r.sd < EPSILON)
            return r.emissive;
        t += r.sd;
    }
    return 0.0f;
}
