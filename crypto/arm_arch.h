#ifndef __ARM_ARCH_H__
#define __ARM_ARCH_H__

#if !defined(__ARM_ARCH__)
# if defined(__CC_ARM)
#  define __ARM_ARCH__ __TARGET_ARCH_ARM
#  if defined(__BIG_ENDIAN)
#   define __ARMEB__
#  else
#   define __ARMEL__
#  endif
# elif defined(__GNUC__)
  /*
   * Why doesn't gcc define __ARM_ARCH__? Instead it defines
   * bunch of below macros. See all_architectires[] table in
   * gcc/config/arm/arm.c. On a side note it defines
   * __ARMEL__/__ARMEB__ for little-/big-endian.
   */
#  if	defined(__ARM_ARCH_7__)	|| defined(__ARM_ARCH_7A__)	|| \
	defined(__ARM_ARCH_7R__)|| defined(__ARM_ARCH_7M__)	|| \
	defined(__ARM_ARCH_7EM)
#   define __ARM_ARCH__ 7
#  elif	defined(__ARM_ARCH_6__)	|| defined(__ARM_ARCH_6J__)	|| \
	defined(__ARM_ARCH_6K__)|| defined(__ARM_ARCH_6M__)	|| \
	defined(__ARM_ARCH_6Z__)|| defined(__ARM_ARCH_6ZK__)	|| \
	defined(__ARM_ARCH_6T2__)
#   define __ARM_ARCH__ 6
#  elif	defined(__ARM_ARCH_5__)	|| defined(__ARM_ARCH_5T__)	|| \
	defined(__ARM_ARCH_5E__)|| defined(__ARM_ARCH_5TE__)
#   define __ARM_ARCH__ 5
#  elif	defined(__ARM_ARCH_4__)	|| defined(__ARM_ARCH_4T__)
#   define __ARM_ARCH__ 4
#  else
#   error "unsupported ARM architecture"
#  endif
# endif

#endif
#endif