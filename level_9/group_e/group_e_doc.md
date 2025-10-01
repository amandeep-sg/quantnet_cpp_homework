# E.a
## Question
Compile and run the  sample programs  TestSingleCurve.cpp, TestTwoCurve.cpp and TestMultipleCurve.cpp.
Make sure that everything compiles and that you get Excel output.

## Output
To execute the code, following amendments were made

1. Following import comands were used in ExcelImports.cpp and rest were commented out

```
#import "C:\Program Files\Microsoft Office\root\VFS\ProgramFilesCommonX86\Microsoft Shared\OFFICE16\MSO.DLL" rename("DocumentProperties", "DocumentPropertiesXL") rename("RGB", "RGBXL")

#import "C:\Program Files\Microsoft Office\root\VFS\ProgramFilesCommonX86\Microsoft Shared\VBA\VBA6\VBE6EXT.OLB"

#import "C:\Program Files\Microsoft Office\root\Office16\EXCEL.EXE" rename("DialogBox", "DialogBoxXL") rename("RGB", "RGBXL") rename("DocumentProperties", "DocumentPropertiesXL") rename("ReplaceText", "ReplaceTextXL") rename("CopyFile", "CopyFileXL") no_dual_interfaces
```

2. Path of #include were modifies as per the set directory structure

The following output excel files are saved in excel_output folder
1. [Test Single Curve](./excel_output/TestSingleCurve.xlsx)
2. [Test Two Curve](./excel_output/TestTwoCurve.xlsx)
3. [Test Multi Curve](./excel_output/TestMultiCurve.xlsx)

# E.b
## Question
We  now  wish  to  compute  option  price  for  a  monotonically  increasing  range  of  underlying  values  of  S,  for example 10, 11, 12, ..., 50. To this end, the output will be a vector and this exercise entails calling the exact option   pricing   formulae)   for   each   value   S   and   each   computed   option   price   will   be   stored   in   a std::vector<double> object.  
It  will  be  useful  to  write  a  global  function  that  produces  a  mesh  array of double separated by a mesh size h. Print the output in Excel.

## Output
To generate the output, the main code is written in **OptionSimulation.cpp**. The following output file is saved in excel_output folder
1. [Option Simulator](./excel_output/OptionSimulator.xlsx)

# Note:
To create the binary, the [compile.bat](./compile.bat) is ceated. To run the script, `./compile.bat` is executed in cmd/poowershell.
