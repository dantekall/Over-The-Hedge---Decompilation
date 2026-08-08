// physics/multi_sphere.cpp
void RegisterMultiSphereCollision(void) {
    if (DAT_0041ab14 < DAT_0041ab18) {
        *DAT_0041ab14 = "TtMultiSphere";
        DAT_0041ab14[1] = PCR0;
        DAT_0041ab14[2] = PCR1;
        DAT_0041ab14 = DAT_0041ab14 + 3;
    }
}