 
 if (as != ADDRESS_SPACE_GLOBAL || !(addr & 0xFF00000000000000))
    return (uptr)((__SYCL_GLOBAL__ MsanLaunchInfo *)__MsanLaunchInfo.get())
        ->CleanShadow;
