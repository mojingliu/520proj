.source Fake.java
.class public Fake
.super java/lang/Object

.method public m(Z)V
.limit stack 1
.limit locals 2
iload_1
ifne true0
goto false1
true0:
iconst_1
goto endif2
false1:
ldc "one"
endif2:
return
.end method

.method public <init>()V
.limit stack 1
.limit locals 1
aload_0
invokespecial java/lang/Object/<init>()V
return
.end method

.method public static <clinit>()V
.limit stack 0
.limit locals 0
return
.end method
