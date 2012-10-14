.source Fake.java
.class public Fake
.super java/lang/Object

.method public m()I
.limit stack 2
.limit locals 4
new Fake
dup
invokespecial Fake/<init>()V
astore_1
new Fake
dup
invokespecial Fake/<init>()V
astore_2
aload_1
aload_2
iadd
ireturn
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
