pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with Interfaces.C.Extensions;
with Interfaces.C.Strings;

package corecrt_h is

   subtype size_t is Extensions.unsigned_long_long;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:40

   subtype ssize_t is Long_Long_Integer;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:50

   subtype rsize_t is size_t;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:57

   subtype intptr_t is Long_Long_Integer;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:67

   subtype uintptr_t is Extensions.unsigned_long_long;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:80

   subtype ptrdiff_t is Long_Long_Integer;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:93

   subtype wint_t is unsigned_short;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:111

   subtype wctype_t is unsigned_short;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:112

   subtype errno_t is int;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:118

   subtype uu_time32_t is long;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:123

   subtype uu_time64_t is Long_Long_Integer;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:128

   subtype time_t is uu_time64_t;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:143

   type threadmbcinfostruct is null record;   -- incomplete struct

   type threadlocaleinfostruct;
   type pthreadlocinfo is access all threadlocaleinfostruct;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:437

   type pthreadmbcinfo is access all threadmbcinfostruct;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:438

   type uu_lc_time_data is null record;   -- incomplete struct

   type localeinfo_struct is record
      locinfo : pthreadlocinfo;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:442
      mbcinfo : pthreadmbcinfo;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:443
   end record
   with Convention => C_Pass_By_Copy;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:441

   subtype u_locale_tstruct is localeinfo_struct;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:444

   type u_locale_t is access all localeinfo_struct;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:444

   type tagLC_ID is record
      wLanguage : aliased unsigned_short;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:449
      wCountry : aliased unsigned_short;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:450
      wCodePage : aliased unsigned_short;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:451
   end record
   with Convention => C_Pass_By_Copy;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:448

   subtype LC_ID is tagLC_ID;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:452

   type LPLC_ID is access all tagLC_ID;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:452

   type anon_anon_1 is record
      locale : Interfaces.C.Strings.chars_ptr;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:469
      wlocale : access wchar_t;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:470
      refcount : access int;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:471
      wrefcount : access int;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:472
   end record
   with Convention => C_Pass_By_Copy;
   type threadlocaleinfostruct_array893 is array (0 .. 5) of aliased unsigned_long;
   type threadlocaleinfostruct_array895 is array (0 .. 5) of aliased LC_ID;
   type threadlocaleinfostruct_array899 is array (0 .. 5) of aliased anon_anon_1;
   type lconv;
   type threadlocaleinfostruct is record
      refcount : aliased int;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:463
      lc_codepage : aliased unsigned;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:464
      lc_collate_cp : aliased unsigned;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:465
      lc_handle : aliased threadlocaleinfostruct_array893;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:466
      lc_id : aliased threadlocaleinfostruct_array895;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:467
      lc_category : aliased threadlocaleinfostruct_array899;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:473
      lc_clike : aliased int;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:474
      mb_cur_max : aliased int;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:475
      lconv_intl_refcount : access int;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:476
      lconv_num_refcount : access int;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:477
      lconv_mon_refcount : access int;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:478
      the_lconv : access lconv;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:479
      ctype1_refcount : access int;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:480
      ctype1 : access unsigned_short;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:481
      pctype : access unsigned_short;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:482
      pclmap : access unsigned_char;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:483
      pcumap : access unsigned_char;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:484
      lc_time_curr : access uu_lc_time_data;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:485
   end record
   with Convention => C_Pass_By_Copy;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:457

   type lconv is null record;   -- incomplete struct

   subtype threadlocinfo is threadlocaleinfostruct;  -- D:/Dev/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h:487

end corecrt_h;
