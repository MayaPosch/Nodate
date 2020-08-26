pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with System;

package vadefs_h is

   subtype uu_gnuc_va_list is System.Address;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/vadefs.h:24

   subtype va_list is uu_gnuc_va_list;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/vadefs.h:31

end vadefs_h;
