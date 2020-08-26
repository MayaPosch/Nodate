pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;

package stm32f0_stm32f0xx_h is

   --  arg-macro: function IS_FUNCTIONAL_STATE (STATE)
   --    return ((STATE) = DISABLE)  or else  ((STATE) = ENABLE);
   --  arg-macro: function SET_BIT (REG, BIT)
   --    return (REG) |= (BIT);
   --  arg-macro: function CLEAR_BIT (REG, BIT)
   --    return (REG) &= ~(BIT);
   --  arg-macro: function READ_BIT (REG, BIT)
   --    return (REG) and (BIT);
   --  arg-macro: function CLEAR_REG (REG)
   --    return (REG) := (16#0#);
   --  arg-macro: function WRITE_REG (REG, VAL)
   --    return (REG) := (VAL);
   --  arg-macro: function READ_REG (REG)
   --    return (REG);
   --  arg-macro: procedure MODIFY_REG (REG, CLEARMASK, SETMASK)
   --    WRITE_REG((REG), (((READ_REG(REG)) and (~(CLEARMASK))) or (SETMASK)))
   type FlagStatus is 
     (RESET,
      SET)
   with Convention => C;  -- ../core/include/stm32f0/stm32f0xx.h:163

   subtype ITStatus is FlagStatus;  -- ../core/include/stm32f0/stm32f0xx.h:163

   type FunctionalState is 
     (DISABLE,
      ENABLE)
   with Convention => C;  -- ../core/include/stm32f0/stm32f0xx.h:169

   type ErrorStatus is 
     (SUCCESS,
      ERROR)
   with Convention => C;  -- ../core/include/stm32f0/stm32f0xx.h:176

end stm32f0_stm32f0xx_h;
