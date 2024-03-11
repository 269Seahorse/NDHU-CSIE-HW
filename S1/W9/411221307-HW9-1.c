int main() {
  init();
  void *p = &block;
  printf("%d, %c, %f", *(int*)p, *(char*)(p + 4), *(float*)(p + 5));
  return 0;
}
