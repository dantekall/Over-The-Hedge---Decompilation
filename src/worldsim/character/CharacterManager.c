extern int func_003EF9FC(void*, char*);

int func_00139DB8(void* name) {
    if (!func_003EF9FC(name, "RJ")) return 0;
    if (!func_003EF9FC(name, "Verne")) return 1;
    if (!func_003EF9FC(name, "Stella")) return 2;
    return func_003EF9FC(name, "Hammy") ? 0 : 3;
}
