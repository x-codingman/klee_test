; ModuleID = '/home/klee/klee_test/threadx_test/evaluation/test_files/test_api_1.bc'
source_filename = "test_api_1.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.test_structure_1 = type { i32, i32* }

@.str = private unnamed_addr constant [11 x i8] c"test_ptr_1\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 !dbg !7 {
entry:
  %test_ptr_1 = alloca %struct.test_structure_1*, align 8
  call void @llvm.dbg.declare(metadata %struct.test_structure_1** %test_ptr_1, metadata !11, metadata !DIExpression()), !dbg !20
  %0 = bitcast %struct.test_structure_1** %test_ptr_1 to i8*, !dbg !21
  call void @klee_make_symbolic_controllable(i8* %0, i64 8, i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str, i64 0, i64 0), i1 zeroext true), !dbg !22
  %1 = load %struct.test_structure_1*, %struct.test_structure_1** %test_ptr_1, align 8, !dbg !23
  call void @test_api_1(%struct.test_structure_1* %1), !dbg !24
  ret i32 0, !dbg !25
}

; Function Attrs: nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

declare dso_local void @klee_make_symbolic_controllable(i8*, i64, i8*, i1 zeroext) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @test_api_1(%struct.test_structure_1* %test_ptr_1) #0 !dbg !26 {
entry:
  %test_ptr_1.addr = alloca %struct.test_structure_1*, align 8
  store %struct.test_structure_1* %test_ptr_1, %struct.test_structure_1** %test_ptr_1.addr, align 8
  call void @llvm.dbg.declare(metadata %struct.test_structure_1** %test_ptr_1.addr, metadata !29, metadata !DIExpression()), !dbg !30
  %0 = load %struct.test_structure_1*, %struct.test_structure_1** %test_ptr_1.addr, align 8, !dbg !31
  %cmp = icmp ugt %struct.test_structure_1* %0, inttoptr (i64 2415919103 to %struct.test_structure_1*), !dbg !33
  br i1 %cmp, label %if.then, label %lor.lhs.false, !dbg !34

lor.lhs.false:                                    ; preds = %entry
  %1 = load %struct.test_structure_1*, %struct.test_structure_1** %test_ptr_1.addr, align 8, !dbg !35
  %cmp1 = icmp ult %struct.test_structure_1* %1, inttoptr (i64 2147483648 to %struct.test_structure_1*), !dbg !36
  br i1 %cmp1, label %if.then, label %if.end4, !dbg !37

if.then:                                          ; preds = %lor.lhs.false, %entry
  %2 = load %struct.test_structure_1*, %struct.test_structure_1** %test_ptr_1.addr, align 8, !dbg !38
  %a = getelementptr inbounds %struct.test_structure_1, %struct.test_structure_1* %2, i32 0, i32 0, !dbg !41
  %3 = load i32, i32* %a, align 8, !dbg !41
  %cmp2 = icmp eq i32 %3, 0, !dbg !42
  br i1 %cmp2, label %if.then3, label %if.end, !dbg !43

if.then3:                                         ; preds = %if.then
  %4 = load %struct.test_structure_1*, %struct.test_structure_1** %test_ptr_1.addr, align 8, !dbg !44
  %p = getelementptr inbounds %struct.test_structure_1, %struct.test_structure_1* %4, i32 0, i32 1, !dbg !46
  %5 = load i32*, i32** %p, align 8, !dbg !46
  store i32 0, i32* %5, align 4, !dbg !47
  br label %if.end, !dbg !48

if.end:                                           ; preds = %if.then3, %if.then
  br label %if.end4, !dbg !49

if.end4:                                          ; preds = %if.end, %lor.lhs.false
  ret void, !dbg !50
}

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone speculatable willreturn }
attributes #2 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!3, !4, !5}
!llvm.ident = !{!6}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 11.0.0 (https://github.com/llvm/llvm-project.git 60a25202a7dd1e00067fcfce512086ebf3788537)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !2, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "test_api_1.c", directory: "/home/klee/klee_test/threadx_test/evaluation/test_files")
!2 = !{}
!3 = !{i32 7, !"Dwarf Version", i32 4}
!4 = !{i32 2, !"Debug Info Version", i32 3}
!5 = !{i32 1, !"wchar_size", i32 4}
!6 = !{!"clang version 11.0.0 (https://github.com/llvm/llvm-project.git 60a25202a7dd1e00067fcfce512086ebf3788537)"}
!7 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 9, type: !8, scopeLine: 9, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!8 = !DISubroutineType(types: !9)
!9 = !{!10}
!10 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!11 = !DILocalVariable(name: "test_ptr_1", scope: !7, file: !1, line: 10, type: !12)
!12 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !13, size: 64)
!13 = !DIDerivedType(tag: DW_TAG_typedef, name: "test_structure_1_t", file: !14, line: 9, baseType: !15)
!14 = !DIFile(filename: "./test_api.h", directory: "/home/klee/klee_test/threadx_test/evaluation/test_files")
!15 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "test_structure_1", file: !14, line: 6, size: 128, elements: !16)
!16 = !{!17, !18}
!17 = !DIDerivedType(tag: DW_TAG_member, name: "a", scope: !15, file: !14, line: 7, baseType: !10, size: 32)
!18 = !DIDerivedType(tag: DW_TAG_member, name: "p", scope: !15, file: !14, line: 8, baseType: !19, size: 64, offset: 64)
!19 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !10, size: 64)
!20 = !DILocation(line: 10, column: 27, scope: !7)
!21 = !DILocation(line: 11, column: 37, scope: !7)
!22 = !DILocation(line: 11, column: 5, scope: !7)
!23 = !DILocation(line: 12, column: 16, scope: !7)
!24 = !DILocation(line: 12, column: 5, scope: !7)
!25 = !DILocation(line: 13, column: 1, scope: !7)
!26 = distinct !DISubprogram(name: "test_api_1", scope: !1, file: !1, line: 15, type: !27, scopeLine: 15, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!27 = !DISubroutineType(types: !28)
!28 = !{null, !12}
!29 = !DILocalVariable(name: "test_ptr_1", arg: 1, scope: !26, file: !1, line: 15, type: !12)
!30 = !DILocation(line: 15, column: 38, scope: !26)
!31 = !DILocation(line: 16, column: 8, scope: !32)
!32 = distinct !DILexicalBlock(scope: !26, file: !1, line: 16, column: 8)
!33 = !DILocation(line: 16, column: 19, scope: !32)
!34 = !DILocation(line: 16, column: 50, scope: !32)
!35 = !DILocation(line: 16, column: 53, scope: !32)
!36 = !DILocation(line: 16, column: 64, scope: !32)
!37 = !DILocation(line: 16, column: 8, scope: !26)
!38 = !DILocation(line: 17, column: 12, scope: !39)
!39 = distinct !DILexicalBlock(scope: !40, file: !1, line: 17, column: 12)
!40 = distinct !DILexicalBlock(scope: !32, file: !1, line: 16, column: 97)
!41 = !DILocation(line: 17, column: 24, scope: !39)
!42 = !DILocation(line: 17, column: 26, scope: !39)
!43 = !DILocation(line: 17, column: 12, scope: !40)
!44 = !DILocation(line: 18, column: 15, scope: !45)
!45 = distinct !DILexicalBlock(scope: !39, file: !1, line: 17, column: 31)
!46 = !DILocation(line: 18, column: 27, scope: !45)
!47 = !DILocation(line: 18, column: 29, scope: !45)
!48 = !DILocation(line: 19, column: 9, scope: !45)
!49 = !DILocation(line: 20, column: 5, scope: !40)
!50 = !DILocation(line: 21, column: 1, scope: !26)
