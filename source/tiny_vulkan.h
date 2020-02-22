#ifdef TINY_VULKAN_UPDATE

#ifndef GLOBAL_LEVEL_VULKAN_FUNCTION
#define GLOBAL_LEVEL_VULKAN_FUNCTION( function )
#endif

GLOBAL_LEVEL_VULKAN_FUNCTION( vkEnumerateInstanceExtensionProperties )
GLOBAL_LEVEL_VULKAN_FUNCTION( vkEnumerateInstanceLayerProperties )
GLOBAL_LEVEL_VULKAN_FUNCTION( vkCreateInstance )

#undef GLOBAL_LEVEL_VULKAN_FUNCTION

//

#ifndef INSTANCE_LEVEL_VULKAN_FUNCTION
#define INSTANCE_LEVEL_VULKAN_FUNCTION( function )
#endif

INSTANCE_LEVEL_VULKAN_FUNCTION( vkEnumeratePhysicalDevices )
INSTANCE_LEVEL_VULKAN_FUNCTION( vkEnumerateDeviceExtensionProperties )
INSTANCE_LEVEL_VULKAN_FUNCTION( vkGetPhysicalDeviceFeatures )
INSTANCE_LEVEL_VULKAN_FUNCTION( vkGetPhysicalDeviceProperties )
INSTANCE_LEVEL_VULKAN_FUNCTION( vkGetPhysicalDeviceQueueFamilyProperties )
INSTANCE_LEVEL_VULKAN_FUNCTION( vkGetPhysicalDeviceMemoryProperties )
INSTANCE_LEVEL_VULKAN_FUNCTION( vkGetPhysicalDeviceFormatProperties )
INSTANCE_LEVEL_VULKAN_FUNCTION( vkCreateDevice )
INSTANCE_LEVEL_VULKAN_FUNCTION( vkGetDeviceProcAddr )
INSTANCE_LEVEL_VULKAN_FUNCTION( vkDestroyInstance )
#undef INSTANCE_LEVEL_VULKAN_FUNCTION

//

#ifndef INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION
#define INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( function, extension )
#endif

INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( vkGetPhysicalDeviceSurfaceSupportKHR, VK_KHR_SURFACE_EXTENSION_NAME )
INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( vkGetPhysicalDeviceSurfaceCapabilitiesKHR, VK_KHR_SURFACE_EXTENSION_NAME )
INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( vkGetPhysicalDeviceSurfaceFormatsKHR, VK_KHR_SURFACE_EXTENSION_NAME )
INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( vkGetPhysicalDeviceSurfacePresentModesKHR, VK_KHR_SURFACE_EXTENSION_NAME )
INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( vkDestroySurfaceKHR, VK_KHR_SURFACE_EXTENSION_NAME )

#ifdef VK_USE_PLATFORM_WIN32_KHR
INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( vkCreateWin32SurfaceKHR, VK_KHR_WIN32_SURFACE_EXTENSION_NAME )
#elif defined VK_USE_PLATFORM_XCB_KHR
INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( vkCreateXcbSurfaceKHR, VK_KHR_XCB_SURFACE_EXTENSION_NAME )
#elif defined VK_USE_PLATFORM_XLIB_KHR
INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( vkCreateXlibSurfaceKHR, VK_KHR_XLIB_SURFACE_EXTENSION_NAME )
#endif

INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( vkCreateDebugUtilsMessengerEXT, VK_EXT_DEBUG_UTILS_EXTENSION_NAME )
INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( vkCreateDebugReportCallbackEXT, VK_EXT_DEBUG_REPORT_EXTENSION_NAME )
INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( vkDestroyDebugReportCallbackEXT, VK_EXT_DEBUG_REPORT_EXTENSION_NAME )

#undef INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION

//

#ifndef DEVICE_LEVEL_VULKAN_FUNCTION
#define DEVICE_LEVEL_VULKAN_FUNCTION( function )
#endif

DEVICE_LEVEL_VULKAN_FUNCTION( vkGetDeviceQueue )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDeviceWaitIdle )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyDevice )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreateBuffer )
DEVICE_LEVEL_VULKAN_FUNCTION( vkGetBufferMemoryRequirements )
DEVICE_LEVEL_VULKAN_FUNCTION( vkAllocateMemory )
DEVICE_LEVEL_VULKAN_FUNCTION( vkBindBufferMemory )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdPipelineBarrier )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreateImage )
DEVICE_LEVEL_VULKAN_FUNCTION( vkGetImageMemoryRequirements )
DEVICE_LEVEL_VULKAN_FUNCTION( vkBindImageMemory )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreateImageView )
DEVICE_LEVEL_VULKAN_FUNCTION( vkMapMemory )
DEVICE_LEVEL_VULKAN_FUNCTION( vkFlushMappedMemoryRanges )
DEVICE_LEVEL_VULKAN_FUNCTION( vkUnmapMemory )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdCopyBuffer )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdCopyBufferToImage )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdCopyImageToBuffer )
DEVICE_LEVEL_VULKAN_FUNCTION( vkBeginCommandBuffer )
DEVICE_LEVEL_VULKAN_FUNCTION( vkEndCommandBuffer )
DEVICE_LEVEL_VULKAN_FUNCTION( vkQueueSubmit )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyImageView )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyImage )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyBuffer )
DEVICE_LEVEL_VULKAN_FUNCTION( vkFreeMemory )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreateCommandPool )
DEVICE_LEVEL_VULKAN_FUNCTION( vkAllocateCommandBuffers )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreateSemaphore )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreateFence )
DEVICE_LEVEL_VULKAN_FUNCTION( vkWaitForFences )
DEVICE_LEVEL_VULKAN_FUNCTION( vkResetFences )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyFence )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroySemaphore )
DEVICE_LEVEL_VULKAN_FUNCTION( vkResetCommandBuffer )
DEVICE_LEVEL_VULKAN_FUNCTION( vkFreeCommandBuffers )
DEVICE_LEVEL_VULKAN_FUNCTION( vkResetCommandPool )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyCommandPool )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreateBufferView )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyBufferView )
DEVICE_LEVEL_VULKAN_FUNCTION( vkQueueWaitIdle )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreateSampler )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreateDescriptorSetLayout )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreateDescriptorPool )
DEVICE_LEVEL_VULKAN_FUNCTION( vkAllocateDescriptorSets )
DEVICE_LEVEL_VULKAN_FUNCTION( vkUpdateDescriptorSets )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdBindDescriptorSets )
DEVICE_LEVEL_VULKAN_FUNCTION( vkFreeDescriptorSets )
DEVICE_LEVEL_VULKAN_FUNCTION( vkResetDescriptorPool )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyDescriptorPool )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyDescriptorSetLayout )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroySampler )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreateRenderPass )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreateFramebuffer )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyFramebuffer )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyRenderPass )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdBeginRenderPass )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdNextSubpass )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdEndRenderPass )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreatePipelineCache )
DEVICE_LEVEL_VULKAN_FUNCTION( vkGetPipelineCacheData )
DEVICE_LEVEL_VULKAN_FUNCTION( vkMergePipelineCaches )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyPipelineCache )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreateGraphicsPipelines )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreateComputePipelines )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyPipeline )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyEvent )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyQueryPool )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreateShaderModule )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyShaderModule )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreatePipelineLayout )
DEVICE_LEVEL_VULKAN_FUNCTION( vkDestroyPipelineLayout )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdBindPipeline )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdSetViewport )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdSetScissor )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdBindVertexBuffers )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdDraw )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdDrawIndexed )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdDispatch )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdCopyImage )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdPushConstants )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdClearColorImage )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdClearDepthStencilImage )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdBindIndexBuffer )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdSetLineWidth )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdSetDepthBias )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdSetBlendConstants )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdExecuteCommands )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdClearAttachments )
DEVICE_LEVEL_VULKAN_FUNCTION( vkInvalidateMappedMemoryRanges )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCreateQueryPool )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdWriteTimestamp )
DEVICE_LEVEL_VULKAN_FUNCTION( vkCmdResetQueryPool )
DEVICE_LEVEL_VULKAN_FUNCTION( vkGetQueryPoolResults )
#undef DEVICE_LEVEL_VULKAN_FUNCTION

//

#ifndef DEVICE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION
#define DEVICE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( function, extension )
#endif

DEVICE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( vkCreateSwapchainKHR, VK_KHR_SWAPCHAIN_EXTENSION_NAME )
DEVICE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( vkGetSwapchainImagesKHR, VK_KHR_SWAPCHAIN_EXTENSION_NAME )
DEVICE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( vkAcquireNextImageKHR, VK_KHR_SWAPCHAIN_EXTENSION_NAME )
DEVICE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( vkQueuePresentKHR, VK_KHR_SWAPCHAIN_EXTENSION_NAME )
DEVICE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( vkDestroySwapchainKHR, VK_KHR_SWAPCHAIN_EXTENSION_NAME )

#undef DEVICE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION
#undef TINY_VULKAN_UPDATE
#endif

#ifndef TINY_VULKAN_H
#define TINY_VULKAN_H

PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;

//GLOBAL_LEVEL_VULKAN_FUNCTION
PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
PFN_vkCreateInstance vkCreateInstance;
//---

//DEBUG_VULKAN_FUNCTION
PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessengerEXT;
PFN_vkCreateDebugReportCallbackEXT vkCreateDebugReportCallbackEXT;
PFN_vkDestroyDebugReportCallbackEXT vkDestroyDebugReportCallbackEXT;
//

//INSTANCE_LEVEL_VULKAN_FUNCTIONS
PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures;
PFN_vkCreateDevice vkCreateDevice;
PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties;
PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
PFN_vkDestroyInstance vkDestroyInstance;
PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties;
//---

//EXTENSION FUNCTIONS
PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR;
PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR;
PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR;
PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR;
#ifdef VK_USE_PLATFORM_WIN32_KHR
PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR;
#elif defined VK_USE_PLATFORM_XCB_KHR
PFN_vkCreateXcbSurfaceKHR vkCreateXcbSurfaceKHR;
#elif defined VK_USE_PLATFORM_XLIB_KHR
PFN_vkCreateXlibSurfaceKHR vkCreateXlibSurfaceKHR;
#endif
//---

//DEVICE_LEVEL_VULKAN_FUNCTION

PFN_vkGetDeviceQueue vkGetDeviceQueue;
PFN_vkDeviceWaitIdle vkDeviceWaitIdle;
PFN_vkDestroyDevice vkDestroyDevice;
PFN_vkCreateBuffer vkCreateBuffer;
PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements;
PFN_vkAllocateMemory vkAllocateMemory;
PFN_vkBindBufferMemory vkBindBufferMemory;
PFN_vkCmdPipelineBarrier vkCmdPipelineBarrier;
PFN_vkCreateImage vkCreateImage;
PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements;
PFN_vkBindImageMemory vkBindImageMemory;
PFN_vkCreateImageView vkCreateImageView;
PFN_vkMapMemory vkMapMemory;
PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges;
PFN_vkUnmapMemory vkUnmapMemory;
PFN_vkCmdCopyBuffer vkCmdCopyBuffer;
PFN_vkCmdCopyBufferToImage vkCmdCopyBufferToImage;
PFN_vkCmdCopyImageToBuffer vkCmdCopyImageToBuffer;
PFN_vkBeginCommandBuffer vkBeginCommandBuffer;
PFN_vkEndCommandBuffer vkEndCommandBuffer;
PFN_vkQueueSubmit vkQueueSubmit;
PFN_vkDestroyImageView vkDestroyImageView;
PFN_vkDestroyImage vkDestroyImage;
PFN_vkDestroyBuffer vkDestroyBuffer;
PFN_vkFreeMemory vkFreeMemory;
PFN_vkCreateCommandPool vkCreateCommandPool;
PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers;
PFN_vkCreateSemaphore vkCreateSemaphore;
PFN_vkCreateFence vkCreateFence;
PFN_vkWaitForFences vkWaitForFences;
PFN_vkResetFences vkResetFences;
PFN_vkDestroyFence vkDestroyFence;
PFN_vkDestroySemaphore vkDestroySemaphore;
PFN_vkResetCommandBuffer vkResetCommandBuffer;
PFN_vkFreeCommandBuffers vkFreeCommandBuffers;
PFN_vkResetCommandPool vkResetCommandPool;
PFN_vkDestroyCommandPool vkDestroyCommandPool;
PFN_vkCreateBufferView vkCreateBufferView;
PFN_vkDestroyBufferView vkDestroyBufferView;
PFN_vkQueueWaitIdle vkQueueWaitIdle;
PFN_vkCreateSampler vkCreateSampler;
PFN_vkCreateDescriptorSetLayout vkCreateDescriptorSetLayout;
PFN_vkCreateDescriptorPool vkCreateDescriptorPool;
PFN_vkAllocateDescriptorSets vkAllocateDescriptorSets;
PFN_vkUpdateDescriptorSets vkUpdateDescriptorSets;
PFN_vkCmdBindDescriptorSets vkCmdBindDescriptorSets;
PFN_vkFreeDescriptorSets vkFreeDescriptorSets;
PFN_vkResetDescriptorPool vkResetDescriptorPool;
PFN_vkDestroyDescriptorPool vkDestroyDescriptorPool;
PFN_vkDestroyDescriptorSetLayout vkDestroyDescriptorSetLayout;
PFN_vkDestroySampler vkDestroySampler;
PFN_vkCreateRenderPass vkCreateRenderPass;
PFN_vkCreateFramebuffer vkCreateFramebuffer;
PFN_vkDestroyFramebuffer vkDestroyFramebuffer;
PFN_vkDestroyRenderPass vkDestroyRenderPass;
PFN_vkCmdBeginRenderPass vkCmdBeginRenderPass;
PFN_vkCmdNextSubpass vkCmdNextSubpass;
PFN_vkCmdEndRenderPass vkCmdEndRenderPass;
PFN_vkCreatePipelineCache vkCreatePipelineCache;
PFN_vkGetPipelineCacheData vkGetPipelineCacheData;
PFN_vkMergePipelineCaches vkMergePipelineCaches;
PFN_vkDestroyPipelineCache vkDestroyPipelineCache;
PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipelines;
PFN_vkCreateComputePipelines vkCreateComputePipelines;
PFN_vkDestroyPipeline vkDestroyPipeline;
PFN_vkDestroyEvent vkDestroyEvent;
PFN_vkDestroyQueryPool vkDestroyQueryPool;
PFN_vkCreateShaderModule vkCreateShaderModule;
PFN_vkDestroyShaderModule vkDestroyShaderModule;
PFN_vkCreatePipelineLayout vkCreatePipelineLayout;
PFN_vkDestroyPipelineLayout vkDestroyPipelineLayout;
PFN_vkCmdBindPipeline vkCmdBindPipeline;
PFN_vkCmdSetViewport vkCmdSetViewport;
PFN_vkCmdSetScissor vkCmdSetScissor;
PFN_vkCmdBindVertexBuffers vkCmdBindVertexBuffers;
PFN_vkCmdDraw vkCmdDraw;
PFN_vkCmdDrawIndexed vkCmdDrawIndexed;
PFN_vkCmdDispatch vkCmdDispatch;
PFN_vkCmdCopyImage vkCmdCopyImage;
PFN_vkCmdPushConstants vkCmdPushConstants;
PFN_vkCmdClearColorImage vkCmdClearColorImage;
PFN_vkCmdClearDepthStencilImage vkCmdClearDepthStencilImage;
PFN_vkCmdBindIndexBuffer vkCmdBindIndexBuffer;
PFN_vkCmdSetLineWidth vkCmdSetLineWidth;
PFN_vkCmdSetDepthBias vkCmdSetDepthBias;
PFN_vkCmdSetBlendConstants vkCmdSetBlendConstants;
PFN_vkCmdExecuteCommands vkCmdExecuteCommands;
PFN_vkCmdClearAttachments vkCmdClearAttachments;
PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges;
PFN_vkCreateQueryPool vkCreateQueryPool;
PFN_vkCmdWriteTimestamp vkCmdWriteTimestamp;
PFN_vkCmdResetQueryPool vkCmdResetQueryPool;
PFN_vkGetQueryPoolResults vkGetQueryPoolResults;
//---

//DEVICE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION
PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR;
PFN_vkGetSwapchainImagesKHR vkGetSwapchainImagesKHR;
PFN_vkAcquireNextImageKHR vkAcquireNextImageKHR;
PFN_vkQueuePresentKHR vkQueuePresentKHR;
PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR;
//----------------------------------------------------------------------

#define EXPORTED_VULKAN_FUNCTION( name ) PFN_##name name;
#define GLOBAL_LEVEL_VULKAN_FUNCTION( name ) PFN_##name name;
#define INSTANCE_LEVEL_VULKAN_FUNCTION( name ) PFN_##name name;
#define INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( name, extension ) PFN_##name name;
#define DEVICE_LEVEL_VULKAN_FUNCTION( name ) PFN_##name name;
#define DEVICE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( name, extension ) PFN_##name name;
#define TINY_VULKAN_UPDATE
#include "tiny_vulkan.h"

/*
CODING CONVENTIONS (Kyryl): 

First above all you must follow tinyengine coding style.
This specific file contains vulkan specific code only for the most part.
I have few simple rules that I follow and you should too, to keep it consistent.


1. NO 0 struct initialization on vulkan structures (except arrays). (aka memset(..., 0, ...) or {0}) 
2. Struct Variables resemble original struct name but have shortcut at the end
   CI = CreateInfo
   AI = AllocationInfo
   etc ...
   Example: VkImageViewCreateInfo SwchImageViewCI;
   You may add extra prefix like Swch or extra word to indicate the object family.

3. Array names must have Vk prefix and plural form of the word. Single variables do not. 
   Example: 
   VkSwapchainKHR VkSwapchains[10];
   VkSwapchainKHR *VkSwapchains;
   VkSwapchainKHR Swapchain;
   Must resemble the type name, but you may but extra prefix or word if needed.

4. Function names have Vk prefix if you want to indicate vulkan runtime to the user.
   I am not very strict about this, so I use this to outline important stuff.   
   I'll leave this to your liking as long as the code makes sense.

"Omnibus promissibus servanda sunt"

*/


//FORWARD DECLARATIONS
const char *GetVulkanResultString(VkResult result);
s32 MemoryTypeFromProperties(u32 type_bits, VkFlags requirements_mask, VkFlags preferred_mask);
void PostInit();
VkDeviceSize VkDeviceMalloc(VkDeviceSize Size, VkDeviceMemory *DeviceMemory, VkMemoryRequirements MemReq);
void VkDeviceFree(u32 Index, VkDeviceMemory DeviceMemory);
void *ZMalloc(s32 Size, u8 Zoneid);
void ZFree(void *Ptr, u8 Zoneid);
//--------------------


#ifdef TINYENGINE_DEBUG
#define VK_CHECK(call)\
	do {\
		ASSERT(call == VK_SUCCESS,"VK_CHECK: %s", GetVulkanResultString(call));\
	} while (false)

#define VK_MCHECK(call, message)\
	do {\
		ASSERT(call == VK_SUCCESS,"VK_MCHECK: %s | %s", GetVulkanResultString(call), message);\
	} while (false)
#else
//NOTE(Kyryl): 
//VK_CHECK has to exist, even when debug disabled because compiler will remove the
//underlying calls assuming they have no effect, but this is wrong. So just setting a dummy variable
//prevents compiler from getting rid of any function that was placed inside the macro
//like so: VK_CHECK(VeriCoolFunc());
#define VK_CHECK(call){VkResult a = call;};
#define VK_MCHECK(call, message){VkResult a = call;};
#endif


//VULKAN GLOBALS
//-----------------------------------------------------

//UNCATEGORIZED VARS
#define MAX_FRAMES_IN_FLIGHT 5 //must be less than num Semaphores, Fences. 
//-----------------------------------------------------
VkAllocationCallbacks Allocator;
VkAllocationCallbacks *VkAllocators = &Allocator;
VkInstance Instance;
VkDebugReportCallbackEXT VulkanDebugCallback;
u32 CurrentFrame; 
//-----------------------------------------------------

//Gpu init:
VkDevice LogicalDevice;
VkPhysicalDevice GpuDevice;
VkExtensionProperties *VkDeviceExtensionProperties;
u32 DeviceExtPropCount;
VkPhysicalDeviceProperties DeviceProperties;
VkPhysicalDeviceFeatures DeviceFeatures;

//Gpu Queues
#define NUM_QUEUES 1
VkQueue VkQueues[NUM_QUEUES];
u32 QueueIndex[NUM_QUEUES];
float QueuePriority[NUM_QUEUES];

//Surface
VkSurfaceKHR VkSurface;
VkPresentModeKHR PresentationMode;
VkSurfaceCapabilitiesKHR SurfaceCapabilities;

//Swapchain
VkImageUsageFlags SwchImageUsage;
VkSurfaceTransformFlagBitsKHR SwchTransform;
VkExtent2D SwchImageSize;
VkImage *VkSwchImages;
u32 SwchImageCount;
VkColorSpaceKHR SwchImageColorSpace;
VkFormat SwchImageFormat;
VkSwapchainKHR VkSwapchains[10];
VkImageView* VkSwchImageViews;

//RENDERING RESOURCES
/*
Objects are in unified arrays instead of
separate varibles, manage with indexing carefully.
*/
#define NUM_SEMAPHORES 10
#define NUM_FENCES 10
#define NUM_RENDERPASSES 10
#define NUM_FRAMEBUFFERS 10
#define NUM_IMAGEVIEWS 100
#define NUM_PIPELINES 20
#define NUM_PIPELINE_LAYOUTS 20
#define NUM_COMMAND_POOLS 10
#define NUM_COMMAND_BUFFERS 10
//----------------------------------------------------
VkSemaphore VkWaitSemaphores[NUM_SEMAPHORES];
VkSemaphore VkSignalSemaphores[NUM_SEMAPHORES];
VkFence VkFences[NUM_FENCES];
VkRenderPass VkRenderPasses[NUM_RENDERPASSES];
VkFramebuffer VkFramebuffers[NUM_FRAMEBUFFERS];
VkImageView VkImageViews[NUM_IMAGEVIEWS];
VkPipeline VkPipelines[NUM_PIPELINES];
VkPipelineLayout VkPipelineLayouts[NUM_PIPELINE_LAYOUTS];
VkCommandPool VkCommandPools[NUM_COMMAND_POOLS];
VkCommandBuffer VkCommandBuffers[NUM_COMMAND_BUFFERS];

//FOCUS OBJECTS (1 varible version of objects above if feasible)
VkCommandBuffer CommandBuffer;
//-----------------------------

//DEPTH
VkImage DepthBuffer;
VkImageView DepthBufferView;
VkDeviceMemory DepthBufferMemory;
VkFormat DepthFormat;

//SAMPLERS
VkSampler PointSampler;

//DESCRIPTOR SETS
VkDescriptorPool DescriptorPool;
VkDescriptorSetLayout VertUniformDescriptorSetLayout;
VkDescriptorSetLayout FragUniformDescriptorSetLayout;
VkDescriptorSetLayout FragSamplerDescriptorSetLayout;
VkDescriptorSet VertUniformDescriptorSet;
VkDescriptorSet FragUniformDescriptorSet;
VkDescriptorSet FragSamplerDescriptorSet;

//TEXTURES
#define NUM_TEXTURES 100
//-----------------------------------
u32 TextureCount;
typedef struct texture_t
{
	u8 *Data;
	u32 Width;
	u32 Height;
	u32 HeapIndex;
	VkImage Image;
	VkImageView ImageView;
//May get rid of these later, waste of memory possibly.
	VkImageType ImageType;
	VkImageViewType ImageViewType;
	VkFormat Format;
	VkImageUsageFlags Usage;
}texture_t;
texture_t TexturePool[NUM_TEXTURES];


//MEMORY
//NOTE(Kyryl):
//These structures are conceptually similar but ---
//I want to separate then with an emphasis, to prevent misuse
//And in case of inside allocators multithread, should be no issues.
#define NUM_VBO_BUFFERS 10
#define NUM_IBO_BUFFERS 10
#define NUM_UBO_BUFFERS 10
#define NUM_STAGING_BUFFERS 2
//----------------------------------------------------
VkPhysicalDeviceMemoryProperties DeviceMemoryProperties;

u32 VboAllocCount;
typedef struct vbo_t
{
	VkBuffer Buffer;
	VkDeviceMemory DeviceMemory;
	u32 Size;
	u32 Offset;
	void *Data;
}vbo_t;
vbo_t VertexBuffers[NUM_VBO_BUFFERS];

u32 IboAllocCount;
typedef struct ibo_t
{
	VkBuffer Buffer;
	VkDeviceMemory DeviceMemory;
	u32 Size;
	u32 Offset;
	void *Data;
}ibo_t;
ibo_t IndexBuffers[NUM_IBO_BUFFERS];

#define MAX_UNIFORM_ALLOC 2048
u32 UboAllocCount;
typedef struct ubo_t
{
	VkBuffer Buffer;
	VkDeviceMemory DeviceMemory;
	u32 Size;
	u32 Offset;
	void *Data;
}ubo_t;
ubo_t UniformBuffers[NUM_UBO_BUFFERS];

u32 StagingIndex;
typedef struct staging_t
{
	VkBuffer Buffer;
	VkCommandBuffer CommandBuffer;
	VkFence Fence;
	VkDeviceMemory DeviceMemory;
	b32 Pending;
	b32 Submitted;
	u32 Size;
	u32 Offset;
	void *Data;
}staging_t;
staging_t StagingBuffers[NUM_STAGING_BUFFERS];

#define NUM_DEVICE_HEAPS 100
u32 DeviceHeapCount;
typedef struct device_heap_t
{
	VkDeviceMemory DeviceMemory;
	VkDeviceSize Size;
	VkDeviceSize Offset;
	b32 Free;
}device_heap_t;
device_heap_t DeviceHeaps[NUM_DEVICE_HEAPS];

//INTERNAL SEGMENTED MEMORY MANAGER
#define	ZONEID	0x1d4a11
#define MINFRAGMENT	64

typedef struct memblock_s
{
	s32 Size;	// including the header and possibly tiny fragments
	s32 Tag;	// a tag of 0 is a free block
#ifdef TINYENGINE_DEBUG
	s32 Id;		// should be ZONEID
#endif
	struct memblock_s *Next, *Prev;
} memblock_t;

typedef struct
{
	s32 Size;		// total bytes malloced, including header
	s32 Align;
	volatile u32 MLock;	//Malloc to Free spinlock
	volatile u32 FLock;
	memblock_t Blocklist;	// start / end cap for linked list
	memblock_t *Rover;
} memzone_t;

memzone_t *Mainzone[10];
//------------------------------SGM

//--------------------------------------MEMORY

//POST INIT
VkClearValue VkClearValues[2];
VkClearColorValue ColorValue;
VkImageSubresourceRange ImageSubResourceRange;
VkImageMemoryBarrier EndRenderMemBarrier;
VkImageMemoryBarrier BeginRenderMemBarrier;
VkSubmitInfo SubmitInfo;
VkPresentInfoKHR PresentInfo;
u32 ImageIndex;
VkPipelineStageFlags PipelineStageFlags;
//POST INIT

//SHADERS
#define NUM_SHADERS 20
//--------------------
VkShaderModule VkShaderModules[NUM_SHADERS];
VkPipelineCache PipelineCache; //TODO
u32 ShaderCount;
//------------------SHADERS

//SHADER RESOURCES
typedef struct
{
	float pos[3];   // = vec3
	float tex_coord[2]; // = vec2
	float color[3]; // = vec3
} Vertex;
//SHADER RESOURCES


//----------------------------------------------------VULKAN GLOBALS

const char *GetVulkanResultString(VkResult result)
{
	switch (result)
	{
	case VK_SUCCESS:
		return "Success";
	case VK_NOT_READY:
		return "A fence or query has not yet completed";
	case VK_TIMEOUT:
		return "A wait operation has not completed in the specified time";
	case VK_EVENT_SET:
		return "An event is signaled";
	case VK_EVENT_RESET:
		return "An event is unsignaled";
	case VK_INCOMPLETE:
		return "A return array was too small for the result";
	case VK_ERROR_OUT_OF_HOST_MEMORY:
		return "A host memory allocation has failed";
	case VK_ERROR_OUT_OF_DEVICE_MEMORY:
		return "A device memory allocation has failed";
	case VK_ERROR_INITIALIZATION_FAILED:
		return "Initialization of an object could not be completed for implementation-specific reasons";
	case VK_ERROR_DEVICE_LOST:
		return "The logical or physical device has been lost";
	case VK_ERROR_MEMORY_MAP_FAILED:
		return "Mapping of a memory object has failed";
	case VK_ERROR_LAYER_NOT_PRESENT:
		return "A requested layer is not present or could not be loaded";
	case VK_ERROR_EXTENSION_NOT_PRESENT:
		return "A requested extension is not supported";
	case VK_ERROR_FEATURE_NOT_PRESENT:
		return "A requested feature is not supported";
	case VK_ERROR_INCOMPATIBLE_DRIVER:
		return "The requested version of Vulkan is not supported by the driver or is otherwise incompatible";
	case VK_ERROR_TOO_MANY_OBJECTS:
		return "Too many objects of the type have already been created";
	case VK_ERROR_FORMAT_NOT_SUPPORTED:
		return "A requested format is not supported on this device";
	case VK_ERROR_SURFACE_LOST_KHR:
		return "A surface is no longer available";
	case VK_SUBOPTIMAL_KHR:
		return "A swapchain no longer matches the surface properties exactly, but can still be used";
	case VK_ERROR_OUT_OF_DATE_KHR:
		return "A surface has changed in such a way that it is no longer compatible with the swapchain";
	case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:
		return "The display used by a swapchain does not use the same presentable image layout";
	case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:
		return "The requested window is already connected to a VkSurfaceKHR, or to some other non-Vulkan API";
	case VK_ERROR_VALIDATION_FAILED_EXT:
		return "A validation layer found an error";
	default:
		return "ERROR: UNKNOWN VULKAN ERROR";
	}
}

void SetSizeOfSwapchainImages(u32 x, u32 y)
{
	SwchImageSize.width = x;
	SwchImageSize.height = y;
}


void CreateSwapchain(VkSwapchainKHR *Swapchain, VkSwapchainKHR *OldSwapchain)
{
	if(*Swapchain)
	{
		Warn("CreateSwapchain: *Swapchain != VK_NULL_HANDLE");
	}
	VkSwapchainCreateInfoKHR SwapchainCI;
	SwapchainCI.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
	SwapchainCI.pNext = NULL;
	SwapchainCI.flags = 0;
	SwapchainCI.surface = VkSurface;
	SwapchainCI.minImageCount = SwchImageCount;
	SwapchainCI.imageFormat = SwchImageFormat;
	SwapchainCI.imageColorSpace = SwchImageColorSpace;
	SwapchainCI.imageExtent = SwchImageSize;
	SwapchainCI.imageArrayLayers = 1;
	SwapchainCI.imageUsage = SwchImageUsage;
	SwapchainCI.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
	SwapchainCI.queueFamilyIndexCount = 0;
	SwapchainCI.pQueueFamilyIndices = NULL;
	SwapchainCI.preTransform = SwchTransform;
	SwapchainCI.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
	SwapchainCI.presentMode = PresentationMode;
	SwapchainCI.clipped = VK_TRUE;
	SwapchainCI.oldSwapchain = *OldSwapchain;

	VK_CHECK(vkCreateSwapchainKHR(LogicalDevice, &SwapchainCI, NULL, Swapchain));
	ASSERT(Swapchain, "vkCreateSwapchainKHR failed.");

	if(OldSwapchain != VK_NULL_HANDLE)
	{
		vkDestroySwapchainKHR(LogicalDevice, *OldSwapchain, NULL);
		OldSwapchain = VK_NULL_HANDLE;
	}
}

void CreateSwapchainImageViews()
{
	//Swapchain ImageViews objects.
	VkImageViewCreateInfo SwchImageViewCI;
	SwchImageViewCI.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
	SwchImageViewCI.pNext = NULL;
	SwchImageViewCI.flags = 0;
	SwchImageViewCI.viewType = VK_IMAGE_VIEW_TYPE_2D;
	SwchImageViewCI.format = SwchImageFormat;
	SwchImageViewCI.components.r = VK_COMPONENT_SWIZZLE_R;
	SwchImageViewCI.components.g = VK_COMPONENT_SWIZZLE_G;
	SwchImageViewCI.components.b = VK_COMPONENT_SWIZZLE_B;
	SwchImageViewCI.components.a = VK_COMPONENT_SWIZZLE_A;
	SwchImageViewCI.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	SwchImageViewCI.subresourceRange.baseMipLevel = 0;
	SwchImageViewCI.subresourceRange.levelCount = 1;
	SwchImageViewCI.subresourceRange.baseArrayLayer = 0;
	SwchImageViewCI.subresourceRange.layerCount = 1;

	for(u32 i = 0; i<SwchImageCount; i++)
	{
		SwchImageViewCI.image = VkSwchImages[i];
		VK_CHECK(vkCreateImageView(LogicalDevice, &SwchImageViewCI, 0, &VkSwchImageViews[i]));
	}
}

void CreateSwchFrameBuffers()
{
	VkFramebufferCreateInfo FramebufferCI;
	FramebufferCI.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
	FramebufferCI.pNext = NULL;
	FramebufferCI.flags = 0;
	FramebufferCI.renderPass = VkRenderPasses[0];
	FramebufferCI.attachmentCount = 0;
	FramebufferCI.pAttachments = NULL;
	FramebufferCI.width = SwchImageSize.width;
	FramebufferCI.height = SwchImageSize.height;
	FramebufferCI.layers = 1;

	FramebufferCI.attachmentCount = 2;
	for(u32 i = 0; i < SwchImageCount; i++)
	{
		VkImageView Attachments[] = { VkSwchImageViews[i], DepthBufferView };
		FramebufferCI.pAttachments = Attachments;
		VK_CHECK(vkCreateFramebuffer(LogicalDevice, &FramebufferCI, 0, &VkFramebuffers[i]));
	}
}

VkImage 
CreateImage(VkFormat Format, VkImageType Type, VkImageUsageFlags Usage, u32 Width, u32 Height)
{
	VkImage Img;
	VkImageCreateInfo ImageCI;
	ImageCI.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
	ImageCI.pNext = NULL;
	ImageCI.flags = 0;
	ImageCI.imageType = Type;
	ImageCI.format = Format;
	ImageCI.extent.width = Width;
	ImageCI.extent.height = Height;
	ImageCI.extent.depth = 1;
	ImageCI.mipLevels = 1;
	ImageCI.arrayLayers = 1;
	ImageCI.samples = VK_SAMPLE_COUNT_1_BIT;
	ImageCI.tiling = VK_IMAGE_TILING_OPTIMAL;
	ImageCI.usage = Usage;
	ImageCI.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
	ImageCI.queueFamilyIndexCount = 0;
	ImageCI.pQueueFamilyIndices = NULL;
	ImageCI.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;

	VK_CHECK(vkCreateImage(LogicalDevice, &ImageCI, VkAllocators, &Img));
	return Img;
}

void CreateTexture(texture_t *Texture)
{
	ASSERT(TextureCount < NUM_TEXTURES, "TextureCount > NUM_TEXTURES");
	ASSERT(Texture->Data, "");
	ASSERT(Texture->ImageType, "");
	ASSERT(Texture->Usage, "");
	ASSERT(Texture->Format, "");
	ASSERT(Texture->Width, "");
	ASSERT(Texture->Height, "");

	Texture->Image = CreateImage(Texture->Format, Texture->ImageType, Texture->Usage, Texture->Width, Texture->Height);

	VkMemoryRequirements MemoryRequirements;
	vkGetImageMemoryRequirements(LogicalDevice, Texture->Image, &MemoryRequirements);
	Texture->HeapIndex = DeviceHeapCount;

	VkDeviceMemory DeviceMemory;
	VkDeviceSize Offset = VkDeviceMalloc(MemoryRequirements.size, &DeviceMemory, MemoryRequirements);
	VK_CHECK(vkBindImageMemory(LogicalDevice, Texture->Image, DeviceMemory, Offset));

	VkImageViewCreateInfo ImageViewCI;
	ImageViewCI.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
	ImageViewCI.pNext = NULL;
	ImageViewCI.flags = 0;
	ImageViewCI.viewType = Texture->ImageViewType;
	ImageViewCI.format = Texture->Format;
	ImageViewCI.components.r = VK_COMPONENT_SWIZZLE_R;
	ImageViewCI.components.g = VK_COMPONENT_SWIZZLE_G;
	ImageViewCI.components.b = VK_COMPONENT_SWIZZLE_B;
	ImageViewCI.components.a = VK_COMPONENT_SWIZZLE_A;
	ImageViewCI.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	ImageViewCI.subresourceRange.baseMipLevel = 0;
	ImageViewCI.subresourceRange.levelCount = 1;
	ImageViewCI.subresourceRange.baseArrayLayer = 0;
	ImageViewCI.subresourceRange.layerCount = 1;

	ImageViewCI.image = Texture->Image;
	VK_CHECK(vkCreateImageView(LogicalDevice, &ImageViewCI, VkAllocators, &Texture->ImageView));
	TextureCount++;
}

void UploadTexture(texture_t *Texture)
{
	ASSERT(Texture->Data, "UploadTexture: Texture->Data == NULL");

	u8 Size = Texture->Width * Texture->Height * 4;
	u8 *Transfer = (u8*)ZMalloc(Size, 4);
	memcpy(Transfer, Texture->Data, Size);

	staging_t *StagingBuffer = &StagingBuffers[StagingIndex];

	VkBufferImageCopy BufferIC;
	BufferIC.bufferOffset = Transfer - (u8*)StagingBuffer->Data;
	BufferIC.bufferRowLength = 0;
	BufferIC.bufferImageHeight = 0;
	BufferIC.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	BufferIC.imageSubresource.mipLevel = 0;
	BufferIC.imageSubresource.baseArrayLayer = 0;
	BufferIC.imageSubresource.layerCount = 1;
	BufferIC.imageOffset.x = 0;
	BufferIC.imageOffset.y = 0;
	BufferIC.imageOffset.z = 0;
	BufferIC.imageExtent.width = Texture->Width;
	BufferIC.imageExtent.height = Texture->Height;
	BufferIC.imageExtent.depth = 1;

	VkImageMemoryBarrier MemBarrier;
	MemBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
	MemBarrier.pNext = NULL;
	MemBarrier.srcAccessMask = 0;
	MemBarrier.dstAccessMask = VK_ACCESS_MEMORY_WRITE_BIT;
	MemBarrier.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
	MemBarrier.newLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
	MemBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
	MemBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
	MemBarrier.image = Texture->Image;
	MemBarrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	MemBarrier.subresourceRange.baseMipLevel = 0;
	MemBarrier.subresourceRange.levelCount = 1;
	MemBarrier.subresourceRange.baseArrayLayer = 0;
	MemBarrier.subresourceRange.layerCount = 1;
	vkCmdPipelineBarrier(StagingBuffer->CommandBuffer, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, NULL, 0, NULL, 1, &MemBarrier);

	vkCmdCopyBufferToImage(StagingBuffer->CommandBuffer, StagingBuffer->Buffer, Texture->Image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &BufferIC);

	MemBarrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
	MemBarrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
	MemBarrier.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
	MemBarrier.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
	vkCmdPipelineBarrier(StagingBuffer->CommandBuffer, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, NULL, 0, NULL, 1, &MemBarrier);
	StagingBuffer->Pending = true;
}

void ResetStagingBuffer()
{
	staging_t *StagingBuffer = &StagingBuffers[StagingIndex];
	if(!StagingBuffer->Submitted)
	{
		Warn("ResetStagingBuffer: Unsubmitted buffer. %d", StagingIndex);
		return; 
	}

	VK_CHECK(vkWaitForFences(LogicalDevice, 1, &StagingBuffer->Fence, VK_TRUE, UINT64_MAX));

	VK_CHECK(vkResetFences(LogicalDevice, 1, &StagingBuffer->Fence));

	VkCommandBufferBeginInfo CommandBufferBI;
	CommandBufferBI.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
	CommandBufferBI.pNext = NULL;
	CommandBufferBI.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT; 
	CommandBufferBI.pInheritanceInfo = NULL;

	VK_MCHECK(vkBeginCommandBuffer(StagingBuffer->CommandBuffer, &CommandBufferBI),"vkBeginCommandBuffer failed!");

	ZFree(StagingBuffer->Data, 4);
	StagingBuffer->Data = NULL;
	StagingBuffer->Offset = 0;
	StagingBuffer->Pending = false;
	StagingBuffer->Submitted = false;
	//Prevent u32 overflow.
	if(StagingIndex == 0)
	{
		return;
	}
	StagingIndex--;
}

b32 SubmitStagingBuffer()
{
	if(StagingIndex == NUM_STAGING_BUFFERS)
	{
		StagingIndex--;
		for(u32 i = 0; i < NUM_STAGING_BUFFERS; i++)
		{
			ResetStagingBuffer();
		}
	}
	staging_t *StagingBuffer = &StagingBuffers[StagingIndex];
	if(StagingBuffer->Pending == false)
	{
		return false; 
	}

	VkMemoryBarrier BufferMemBarrier;
	BufferMemBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
	BufferMemBarrier.pNext = NULL;
	BufferMemBarrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
	BufferMemBarrier.dstAccessMask = VK_ACCESS_INDEX_READ_BIT | VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT;
	vkCmdPipelineBarrier(StagingBuffer->CommandBuffer, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_VERTEX_INPUT_BIT, 0, 0, &BufferMemBarrier, 0, NULL, 0, NULL);

	vkEndCommandBuffer(StagingBuffer->CommandBuffer);

	//TODO(Kyryl): Check, I think this flush is optional.
	VkMappedMemoryRange MemRange;
	MemRange.sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE;
	MemRange.pNext = NULL;
	MemRange.memory = StagingBuffer->DeviceMemory;
	MemRange.offset = 0;
	MemRange.size = VK_WHOLE_SIZE;
	vkFlushMappedMemoryRanges(LogicalDevice, 1, &MemRange);

	VkSubmitInfo SubmitInfo;
	SubmitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
	SubmitInfo.pNext = NULL;
	SubmitInfo.waitSemaphoreCount = 0;
	SubmitInfo.pWaitSemaphores = NULL;
	SubmitInfo.pWaitDstStageMask = NULL;
	SubmitInfo.commandBufferCount = 1;
	SubmitInfo.pCommandBuffers = &StagingBuffer->CommandBuffer;
	SubmitInfo.signalSemaphoreCount = 0;
	SubmitInfo.pSignalSemaphores = NULL;

	vkQueueSubmit(VkQueues[0], 1, &SubmitInfo, StagingBuffer->Fence);

	StagingBuffer->Submitted = true;
	StagingIndex++;
	return true;
}

void DestroyDepthBuffer()
{
	vkDestroyImage(LogicalDevice, DepthBuffer, VkAllocators);
	vkFreeMemory(LogicalDevice, DepthBufferMemory, VkAllocators);
	vkDestroyImageView(LogicalDevice, DepthBufferView, VkAllocators);
}

void CreateDepthBuffer()
{
	Trace("Creating depth buffer");

	if(DepthBuffer)
	{
		DestroyDepthBuffer();
	}

	DepthBuffer = CreateImage(DepthFormat, VK_IMAGE_TYPE_2D, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT, SwchImageSize.width, SwchImageSize.height);

	VkMemoryRequirements MemoryRequirements;
	vkGetImageMemoryRequirements(LogicalDevice, DepthBuffer, &MemoryRequirements);

	VkMemoryAllocateInfo MemoryAI;
	MemoryAI.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
	MemoryAI.pNext = NULL;
	MemoryAI.allocationSize = MemoryRequirements.size;
	MemoryAI.memoryTypeIndex = MemoryTypeFromProperties(MemoryRequirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, 0);

	VK_CHECK(vkAllocateMemory(LogicalDevice, &MemoryAI, VkAllocators, &DepthBufferMemory));
	VK_CHECK(vkBindImageMemory(LogicalDevice, DepthBuffer, DepthBufferMemory, 0));

	VkImageViewCreateInfo DepthBufferImageViewCI;
	DepthBufferImageViewCI.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
	DepthBufferImageViewCI.pNext = NULL;
	DepthBufferImageViewCI.flags = 0;
	DepthBufferImageViewCI.image = DepthBuffer;
	DepthBufferImageViewCI.viewType = VK_IMAGE_VIEW_TYPE_2D;
	DepthBufferImageViewCI.format = DepthFormat;
	DepthBufferImageViewCI.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
	DepthBufferImageViewCI.components.g = VK_COMPONENT_SWIZZLE_IDENTITY; 
	DepthBufferImageViewCI.components.b = VK_COMPONENT_SWIZZLE_IDENTITY; 
	DepthBufferImageViewCI.components.a = VK_COMPONENT_SWIZZLE_IDENTITY; 
	DepthBufferImageViewCI.subresourceRange.aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT;
	DepthBufferImageViewCI.subresourceRange.baseMipLevel = 0;
	DepthBufferImageViewCI.subresourceRange.levelCount = 1;
	DepthBufferImageViewCI.subresourceRange.baseArrayLayer = 0;
	DepthBufferImageViewCI.subresourceRange.layerCount = 1;

	VK_CHECK(vkCreateImageView(LogicalDevice, &DepthBufferImageViewCI, VkAllocators, &DepthBufferView));
}

s32 MemoryTypeFromProperties(u32 type_bits, VkFlags requirements_mask, VkFlags preferred_mask)
{
	u32 current_type_bits = type_bits;
	u32 i;

	for (i = 0; i < VK_MAX_MEMORY_TYPES; i++)
	{
		if ((current_type_bits & 1) == 1)
		{
			if ((DeviceMemoryProperties.memoryTypes[i].propertyFlags & (requirements_mask | preferred_mask)) == (requirements_mask | preferred_mask))
				return i;
		}
		current_type_bits >>= 1;
	}

	current_type_bits = type_bits;
	for (i = 0; i < VK_MAX_MEMORY_TYPES; i++)
	{
		if ((current_type_bits & 1) == 1)
		{
			if ((DeviceMemoryProperties.memoryTypes[i].propertyFlags & requirements_mask) == requirements_mask)
				return i;
		}
		current_type_bits >>= 1;
	}

	Fatal("Could not find memory type");
	return 0;
}

//NOTE(Kyryl):
//These tiny allocators are designed for permanent objects.
//Incompatible with SGM, use .Offset member in struct to keep
//track of position. 
u8 *VboDigress(u32 Size, u8 BufIndex, VkDeviceSize *Offset)
{
	*Offset = VertexBuffers[BufIndex].Offset;
	ASSERT(*Offset + Size < VertexBuffers[BufIndex].Size, "VboDigress: out of memory");
	u8 *Data = (u8*)VertexBuffers[BufIndex].Data + *Offset;
	VertexBuffers[BufIndex].Offset += Size;
	return Data;
}

u8 *IboDigress(u32 Size, u8 BufIndex, VkDeviceSize *Offset)
{
	Size = (Size + (sizeof(u32)-1)) & -sizeof(u32);
	*Offset = IndexBuffers[BufIndex].Offset;
	ASSERT(*Offset + Size < IndexBuffers[BufIndex].Size, "IboDigress: out of memory");
	u8 *Data = (u8*)IndexBuffers[BufIndex].Data + *Offset;
	IndexBuffers[BufIndex].Offset += Size;
	return Data;
}

u8 *UboDigress(u32 Size, u8 BufIndex, VkDeviceSize *Offset)
{
	Size = (Size + (256-1)) & -256;
	*Offset = UniformBuffers[BufIndex].Offset;
	ASSERT(*Offset + Size < UniformBuffers[BufIndex].Size, "UboDigress: out of memory");
	u8 *Data = (u8*)UniformBuffers[BufIndex].Data + *Offset;
	UniformBuffers[BufIndex].Offset += Size;
	return Data;
}
//NOTE(Kyryl):
//There will be one huge buffer, so in theory this function
//should be called only once per memory type, but may be used in case of scarcity
void *VkHostMalloc(u32 Size, VkBuffer *Buffer, VkDeviceMemory *DeviceMemory, VkBufferUsageFlagBits Usage)
{
	VkBufferCreateInfo BufferCI;
	BufferCI.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
	BufferCI.pNext = NULL;
	BufferCI.flags = 0;
	BufferCI.size = Size;
	BufferCI.usage = Usage;
	BufferCI.sharingMode = 0;
	BufferCI.queueFamilyIndexCount = 0;
	BufferCI.pQueueFamilyIndices = NULL;

	VK_MCHECK(vkCreateBuffer(LogicalDevice, &BufferCI, VkAllocators, Buffer), "vkCreateBuffer failed!");

	VkMemoryRequirements MemoryRequirements;
	vkGetBufferMemoryRequirements(LogicalDevice, *Buffer, &MemoryRequirements);

	s32 AlignMod = MemoryRequirements.size % MemoryRequirements.alignment;
	s32 AlignedSize = ((MemoryRequirements.size % MemoryRequirements.alignment) == 0)
	                         ? MemoryRequirements.size
	                         : (MemoryRequirements.size + MemoryRequirements.alignment - AlignMod);

	VkMemoryAllocateInfo MemoryAI;
	MemoryAI.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
	MemoryAI.pNext = NULL;
	MemoryAI.allocationSize = AlignedSize;
	MemoryAI.memoryTypeIndex = MemoryTypeFromProperties(MemoryRequirements.memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, VK_MEMORY_PROPERTY_HOST_CACHED_BIT);

	VK_MCHECK(vkAllocateMemory(LogicalDevice, &MemoryAI, VkAllocators, DeviceMemory), "vkAllocateMemory failed!");

	VK_MCHECK(vkBindBufferMemory(LogicalDevice, *Buffer, *DeviceMemory, 0), "vkBindBufferMemory failed!");

	void *Data;
	VK_MCHECK(vkMapMemory(LogicalDevice, *DeviceMemory, 0, AlignedSize, 0, &Data),"vkMapMemory failed!");

	return Data;
}

//NOTE(Kyryl):
//This memory resides in dedicated graphics card and can't be mapped.
//Meaning we can't get direct cpu pointer to it's contents, but we can
//Get vulkan handle and use vulkan commands to operate on it.
VkDeviceSize VkDeviceMalloc(VkDeviceSize Size, VkDeviceMemory *DeviceMemory, VkMemoryRequirements MemReq)
{
	ASSERT(DeviceHeapCount < NUM_DEVICE_HEAPS, "Out of DeviceHeaps.");
	device_heap_t *Heap;
	for(u32 i = 0; i < DeviceHeapCount; i++)
	{
		Heap = &DeviceHeaps[i];
		if(Heap->Free)
		{
			const VkDeviceSize AlignMod = Heap->Offset % MemReq.alignment;
			VkDeviceSize AlignPad = (AlignMod == 0) ? 0 : (MemReq.alignment - AlignMod);
			VkDeviceSize AlignedSize = Size + AlignPad;
			if(Heap->Size == AlignedSize)
			{
				Heap->Free = false;
				return Heap->Offset + AlignPad;
			}
			if(Heap->Size > AlignedSize)
			{
				device_heap_t *NewHeap = &DeviceHeaps[DeviceHeapCount];
				NewHeap->DeviceMemory = Heap->DeviceMemory;
				NewHeap->Size = Size;
				NewHeap->Offset = Heap->Offset + AlignPad;
				NewHeap->Free = false;
				Heap->Size -= AlignedSize;
				Heap->Offset += AlignedSize;
				DeviceHeapCount++;
				return NewHeap->Offset;
			}
		}

	}
	VkMemoryAllocateInfo MemoryAI;
	MemoryAI.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
	MemoryAI.pNext = NULL;
	MemoryAI.allocationSize = Size;
	MemoryAI.memoryTypeIndex = MemoryTypeFromProperties(MemReq.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, 0);

	VK_MCHECK(vkAllocateMemory(LogicalDevice, &MemoryAI, VkAllocators, DeviceMemory), "vkAllocateMemory failed!");
	Heap = &DeviceHeaps[DeviceHeapCount];
	Heap->DeviceMemory = *DeviceMemory;
	Heap->Size = Size;
	Heap->Offset = 0;
	Heap->Free = 0;
	DeviceHeapCount++;
	return 0;
}

void VkDeviceFree(u32 Index, VkDeviceMemory DeviceMemory)
{
	device_heap_t *Heap;
	if(!DeviceMemory)
	{
		Heap = &DeviceHeaps[Index];
		ASSERT(!Heap->Free, "Tried to free freed device heap!");
		ASSERT(Index < DeviceHeapCount, "VkDeviceFree: allocation index is out of bounds.");
		Heap->Free = true;
		//Merge every free block until the end.
		for(u32 i = 1; Index >= i; Heap = &DeviceHeaps[Index-i], i++)
		{
			if(Heap->Free)
			{
				device_heap_t *Prev = &DeviceHeaps[(Index-i)+1];
				Heap->Size += Prev->Size;
				memset(Prev, 0, sizeof(device_heap_t));
			}	
			else
			{
				break;
			}
		}
		return;
	}
	else
	{
		for(u32 i = 0; i < DeviceHeapCount; i++)
		{
			Heap = &DeviceHeaps[i];
			if(Heap->DeviceMemory == DeviceMemory)
			{
				//NOTE(Kyryl): There will be holes left over. 
				memset(Heap, 0, sizeof(device_heap_t));
			}
		}
		vkFreeMemory(LogicalDevice, DeviceMemory, VkAllocators);
	}

}

void *ZMalloc(s32 Size, u8 Zoneid)
{
	s32 Extra;
	memblock_t *Start, *Rover, *Newblock, *Base;
	memzone_t *Zone = Mainzone[Zoneid];

//
// scan through the block list looking for the first free block
// of sufficient size
//
	Size += sizeof(memblock_t);	// account for size of block header
#ifdef TINYENGINE_DEBUG
	Size += sizeof(s32);		// space for memory trash tester
#endif
	Size = (Size + (Zone->Align-1)) & -Zone->Align;
	//alignment must be consistent through out the allocator.

	Base = Rover = Mainzone[Zoneid]->Rover;
	Start = Base->Prev;

	while(Zone->MLock || Zone->FLock){}
	Zone->MLock = true;

	do
	{
		if (Rover == Start)	// scaned all the way around the list
		{
			//NOTE(Kyryl):
			//Not every allocation does check for NULL so
			//also do notify here.
			//TODO:
			//Instead of returning NULL we can do another OS allocation here
			//and link the last node of that to the blocklist.
			Error("ZMalloc failed!");
			return NULL;
		}
		if (Rover->Tag)
		{
			Base = Rover = Rover->Next;
		}
		else
		{
			Rover = Rover->Next;
		}
	}
	while (Base->Tag || Base->Size < Size);

//
// found a block big enough
//
	Extra = Base->Size - Size;
	if (Extra > MINFRAGMENT)
	{
		// there will be a free fragment after the allocated block
		Newblock = (memblock_t *) ((u8*)Base + Size );
		Newblock->Size = Extra;
		Newblock->Tag = 0;			// free block
		Newblock->Prev = Base;
#ifdef TINYENGINE_DEBUG		
		Newblock->Id = ZONEID;
#endif		
		Newblock->Next = Base->Next;
		Newblock->Next->Prev = Newblock;
		Base->Next = Newblock;
		Base->Size = Size;
	}

	Base->Tag = 1;				// no longer a free block

	Zone->Rover = Base->Next;	// next allocation will start looking here
	
#ifdef TINYENGINE_DEBUG
	// marker for memory trash testing
	Base->Id = ZONEID;
	*(int *)((u8*)Base + Base->Size - sizeof(s32)) = ZONEID;
#endif

	Zone->MLock = false;
	return (void *) ((u8 *)Base + sizeof(memblock_t));
}

void ZFree(void *Ptr, u8 Zoneid)
{
	memblock_t *Block, *Other;
	memzone_t *Zone; 
	if (!Ptr)
	{
		return;
	}

	Zone = Mainzone[Zoneid];
	Block = (memblock_t *) ( (unsigned char *)Ptr - sizeof(memblock_t));
#ifdef TINYENGINE_DEBUG
	if (Block->Id != ZONEID)
	{
		Warn("ZFree: freed a pointer without ZONEID");
	}
	if (Block->Tag == 0)
	{
		Warn("ZFree: freed a freed pointer zoneid: %d", Zoneid);
	}
#endif

	while(Zone->MLock || Zone->FLock){}
	Zone->FLock = true;

	Block->Tag = 0;	// mark as free

	Other = Block->Prev;
	if (!Other->Tag)
	{
		// merge with previous free block
		Other->Size += Block->Size;
		Other->Next = Block->Next;
		Other->Next->Prev = Other;
		if (Block == Zone->Rover)
			Zone->Rover = Other;
		Block = Other;
	}

	Other = Block->Next;
	if (!Other->Tag)
	{
		// merge the next free block onto the end
		Block->Size += Other->Size;
		Block->Next = Other->Next;
		Block->Next->Prev = Block;
		if (Other == Zone->Rover)
			Zone->Rover = Block;
	}
	Zone->FLock = false;
}

void *ZRealloc(void *Ptr, int Size, u8 Zoneid)
{
	int OldSize;
	void *OldPtr;
	memblock_t *Block;

	if (!Ptr)
	{
		return ZMalloc (Size, Zoneid);
	}
	Block = (memblock_t *) ((u8 *) Ptr - sizeof (memblock_t));
	
#ifdef TINYENGINE_DEBUG
	if (Block->Id != ZONEID)
	{
		Warn("ZFree: freed a pointer without ZONEID");
	}
	if (Block->Tag == 0)
	{
		Warn("ZFree: freed a freed pointer zoneid: %d", Zoneid);
	}
#endif
	OldSize = Block->Size;
	
#ifdef TINYENGINE_DEBUG	
	OldSize -= sizeof(int); /* see ZMalloc() */
#endif	
	OldSize -= ((int)sizeof(memblock_t));	
	OldPtr = Ptr;

	ZFree (Ptr, Zoneid);
	Ptr = ZMalloc (Size, Zoneid);
	if (!Ptr)
	{
		Fatal("ZRealloc: failed on allocation of %i bytes", Size);
	}
	if (Ptr != OldPtr)
		memmove (Ptr, OldPtr, Min(OldSize, Size));
	if (OldSize < Size)
		memset((unsigned char *)Ptr + OldSize, 0, Size - OldSize);

	return Ptr;
}

void ZInitZone(void *Mem, u32 Size, u32 Align, u8 Zoneid)
{
	memblock_t *Block;

	memzone_t *Zone = (memzone_t*)Mem;
	Mainzone[Zoneid] = Zone;
	Zone->Align = Align;
// set the entire zone to one free block

	Zone->Blocklist.Next = Zone->Blocklist.Prev = Block =
	                           (memblock_t *)( (u8 *)Zone + sizeof(memzone_t) );
	Zone->Blocklist.Tag = 1; // in use block
#ifdef TINYENGINE_DEBUG
	Zone->Blocklist.Id = 0;
#endif	
	Zone->Blocklist.Size = 0;
	Zone->Rover = Block;

	Block->Prev = Block->Next = &Zone->Blocklist;
	Block->Tag = 0;	// free block
#ifdef TINYENGINE_DEBUG
	Block->Id = ZONEID;
#endif	
	Block->Size = Size - sizeof(memzone_t);
}

void *VkAlloc(void *pusd, size_t size, size_t align, VkSystemAllocationScope allocationScope)
{
	void* p = ZMalloc(size, 0);
	ASSERT(p,"VkAlloc failed.");
	return p;
}

void *VkRealloc(void* pusd, void* porg, size_t size, size_t align, VkSystemAllocationScope allocationScope)
{
	void* p = ZRealloc(porg, size, 0);
	ASSERT(p,"VkRealloc failed.");
	return p;
}

void VkFree(void *pusd, void *ptr)
{
	ZFree(ptr, 0);
	return;
}

void LoadShader(const char* Path)
{
	ASSERT(ShaderCount < NUM_SHADERS, "Out of shader modules, Increase NUM_SHADERS");

	s32 Size;
	u8 *Buffer = Tiny_ReadFile(Path, &Size);

	VkShaderModuleCreateInfo ShaderModuleCI;
	ShaderModuleCI.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	ShaderModuleCI.pNext = NULL;
	ShaderModuleCI.flags = 0;
	ShaderModuleCI.codeSize = Size;
	ShaderModuleCI.pCode = (const u32*)(Buffer);

	VK_CHECK(vkCreateShaderModule(LogicalDevice, &ShaderModuleCI, 0, &VkShaderModules[ShaderCount]));
	Tiny_Free(Buffer);
	ShaderCount++;
}

void LoadHexShader(const u32 *Buffer, u32 Size)
{
	ASSERT(ShaderCount < NUM_SHADERS, "Out of shader modules, Increase NUM_SHADERS");
	VkShaderModuleCreateInfo ShaderModuleCI;
	ShaderModuleCI.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	ShaderModuleCI.pNext = NULL;
	ShaderModuleCI.flags = 0;
	ShaderModuleCI.codeSize = Size;
	ShaderModuleCI.pCode = Buffer;

	VK_CHECK(vkCreateShaderModule(LogicalDevice, &ShaderModuleCI, 0, &VkShaderModules[ShaderCount]));
	ShaderCount++;
}

void CreateBasicShaderPipeline(VkPolygonMode PolygonMode)
{
	VkShaderModule vs = VkShaderModules[0];
	VkShaderModule fs = VkShaderModules[1];

	ASSERT(vs, "Failed to load Vertex Shader.");
	ASSERT(fs, "Failed to load Fragment Shader.");

	VkPipelineShaderStageCreateInfo ShaderStageCI[2];
	ShaderStageCI[0].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	ShaderStageCI[0].pNext = NULL;
	ShaderStageCI[0].flags = 0;
	ShaderStageCI[0].stage = VK_SHADER_STAGE_VERTEX_BIT;
	ShaderStageCI[0].module = vs;
	ShaderStageCI[0].pName = "main";
	ShaderStageCI[0].pSpecializationInfo = NULL;
	ShaderStageCI[1].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	ShaderStageCI[1].pNext = NULL;
	ShaderStageCI[1].flags = 0;
	ShaderStageCI[1].stage = VK_SHADER_STAGE_FRAGMENT_BIT;
	ShaderStageCI[1].module = fs;
	ShaderStageCI[1].pName = "main";
	ShaderStageCI[1].pSpecializationInfo = NULL;

	VkPipelineInputAssemblyStateCreateInfo InputAssemblyCI;
	InputAssemblyCI.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
	InputAssemblyCI.pNext = NULL;
	InputAssemblyCI.flags = 0;
	InputAssemblyCI.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
	InputAssemblyCI.primitiveRestartEnable = VK_FALSE;

	VkPipelineViewportStateCreateInfo ViewportState;
	ViewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
	ViewportState.pNext = NULL;
	ViewportState.flags = 0;
	ViewportState.viewportCount = 1;
	ViewportState.pViewports = NULL;
	ViewportState.scissorCount = 1;
	ViewportState.pScissors = NULL;

	VkPipelineRasterizationStateCreateInfo RasterizationStateCI;
	RasterizationStateCI.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
	RasterizationStateCI.pNext = NULL;
	RasterizationStateCI.flags = 0;
	RasterizationStateCI.depthClampEnable = VK_FALSE;
	RasterizationStateCI.rasterizerDiscardEnable = VK_FALSE;
	RasterizationStateCI.polygonMode = PolygonMode;
	RasterizationStateCI.cullMode = VK_CULL_MODE_NONE;
	RasterizationStateCI.frontFace = VK_FRONT_FACE_CLOCKWISE;
	RasterizationStateCI.depthBiasEnable = VK_FALSE;
	RasterizationStateCI.depthBiasConstantFactor = 0.0f;
	RasterizationStateCI.depthBiasClamp = 0.0f;
	RasterizationStateCI.depthBiasSlopeFactor = 0.0f;
	RasterizationStateCI.lineWidth = 1.0f;

	VkPipelineMultisampleStateCreateInfo MultisampleStateCI;
	MultisampleStateCI.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
	MultisampleStateCI.pNext = NULL;
	MultisampleStateCI.flags = 0;
	MultisampleStateCI.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
	MultisampleStateCI.sampleShadingEnable = VK_FALSE;
	MultisampleStateCI.minSampleShading = 0.0f;
	MultisampleStateCI.pSampleMask = NULL;
	MultisampleStateCI.alphaToCoverageEnable = VK_FALSE;
	MultisampleStateCI.alphaToOneEnable = VK_FALSE;

	VkPipelineDepthStencilStateCreateInfo DepthStensilStateCI;
	DepthStensilStateCI.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
	DepthStensilStateCI.pNext = NULL;
	DepthStensilStateCI.flags = 0;

	VkPipelineColorBlendAttachmentState ColorBlendAttachment;
	ColorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;

	VkPipelineColorBlendStateCreateInfo ColorBlendStateCI;
	ColorBlendStateCI.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
	ColorBlendStateCI.pNext = NULL;
	ColorBlendStateCI.flags = 0;
	ColorBlendStateCI.attachmentCount = 1;
	ColorBlendStateCI.pAttachments = &ColorBlendAttachment;
	ColorBlendStateCI.logicOpEnable = VK_FALSE;
	ColorBlendStateCI.logicOp = VK_LOGIC_OP_COPY;
	ColorBlendStateCI.attachmentCount = 1;
	ColorBlendStateCI.blendConstants[0] = 1.0f;
	ColorBlendStateCI.blendConstants[1] = 1.0f;
	ColorBlendStateCI.blendConstants[2] = 1.0f;
	ColorBlendStateCI.blendConstants[3] = 1.0f;

	VkStencilOpState sos = {0};
	DepthStensilStateCI.depthTestEnable = VK_TRUE;
	DepthStensilStateCI.depthWriteEnable = VK_TRUE;
	DepthStensilStateCI.depthCompareOp = VK_COMPARE_OP_LESS;
	DepthStensilStateCI.depthBoundsTestEnable = VK_FALSE;
	DepthStensilStateCI.stencilTestEnable = VK_FALSE;
	DepthStensilStateCI.front = sos;
	DepthStensilStateCI.back = sos;
	DepthStensilStateCI.minDepthBounds = 0.0f;
	DepthStensilStateCI.maxDepthBounds = 0.0f;

	ColorBlendAttachment.blendEnable = VK_FALSE;
	ColorBlendAttachment.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
	ColorBlendAttachment.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
	ColorBlendAttachment.colorBlendOp = VK_BLEND_OP_ADD;
	ColorBlendAttachment.srcAlphaBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
	ColorBlendAttachment.dstAlphaBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
	ColorBlendAttachment.alphaBlendOp = VK_BLEND_OP_ADD;

	VkDynamicState DynamicStates[] = { VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR };

	VkPipelineDynamicStateCreateInfo PipelineDynamicStateCI;
	PipelineDynamicStateCI.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
	PipelineDynamicStateCI.pNext = NULL;
	PipelineDynamicStateCI.flags = 0;
	PipelineDynamicStateCI.dynamicStateCount = ArrayCount(DynamicStates);
	PipelineDynamicStateCI.pDynamicStates = DynamicStates;

	VkVertexInputBindingDescription VertexInputBD[1]; 
	VertexInputBD[0].binding = 0;
	VertexInputBD[0].stride = sizeof(Vertex);
	VertexInputBD[0].inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

	VkVertexInputAttributeDescription VertexInputAD[3];
	VertexInputAD[0].binding = 0;
	VertexInputAD[0].location = 0;
	VertexInputAD[0].format = VK_FORMAT_R32G32B32_SFLOAT;
	VertexInputAD[0].offset = offsetof(Vertex, pos);
	VertexInputAD[1].binding = 0;
	VertexInputAD[1].location = 1;
	VertexInputAD[1].format = VK_FORMAT_R32G32_SFLOAT;
	VertexInputAD[1].offset = offsetof(Vertex, tex_coord);
	VertexInputAD[2].binding = 0;
	VertexInputAD[2].location = 2;
	VertexInputAD[2].format = VK_FORMAT_R32G32B32_SFLOAT;
	VertexInputAD[2].offset = offsetof(Vertex, color);

	VkPipelineVertexInputStateCreateInfo VertexInputStateCI[1];
	VertexInputStateCI[0].sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
	VertexInputStateCI[0].pNext = NULL;
	VertexInputStateCI[0].flags = 0;
	VertexInputStateCI[0].vertexBindingDescriptionCount = 1;
	VertexInputStateCI[0].vertexAttributeDescriptionCount = 3;
	VertexInputStateCI[0].pVertexBindingDescriptions = VertexInputBD;
	VertexInputStateCI[0].pVertexAttributeDescriptions = &VertexInputAD[0];

	VkGraphicsPipelineCreateInfo PipelineCI;
	PipelineCI.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
	PipelineCI.pNext = NULL;
	PipelineCI.flags = 0;
	PipelineCI.stageCount = ArrayCount(ShaderStageCI);
	PipelineCI.pStages = ShaderStageCI;
	PipelineCI.pVertexInputState = &VertexInputStateCI[0];
	PipelineCI.pInputAssemblyState = &InputAssemblyCI;
	PipelineCI.pTessellationState = NULL;
	PipelineCI.pViewportState = &ViewportState;
	PipelineCI.pRasterizationState = &RasterizationStateCI;
	PipelineCI.pMultisampleState = &MultisampleStateCI;
	PipelineCI.pDepthStencilState = &DepthStensilStateCI;
	PipelineCI.pColorBlendState = &ColorBlendStateCI;
	PipelineCI.pDynamicState = &PipelineDynamicStateCI;
	PipelineCI.layout = VkPipelineLayouts[0];
	PipelineCI.renderPass = VkRenderPasses[0];
	PipelineCI.subpass = 0;
	PipelineCI.basePipelineHandle = 0;
	PipelineCI.basePipelineIndex = 0;

	VK_CHECK(vkCreateGraphicsPipelines(LogicalDevice, PipelineCache, 1, &PipelineCI, 0, &VkPipelines[0]));
	return;
}


#ifdef TINYENGINE_DEBUG

VkBool32 VKAPI_CALL DebugReportCallback(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, u64 object, size_t location, s32 messageCode, const char* pLayerPrefix, const char* pMessage, void* pUserData)
{
	// This silences warnings like "For optimal performance image layout should be VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL instead of GENERAL."
	// We'll assume other performance warnings are also not useful.
	if (flags & VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT)
		return VK_FALSE;

	const char* type =
	    (flags & VK_DEBUG_REPORT_ERROR_BIT_EXT)
	    ? "ERROR"
	    : (flags & VK_DEBUG_REPORT_WARNING_BIT_EXT)
	    ? "WARNING"
	    : "INFO";

	char message[4096];
	stbsp_sprintf(message, "%s: %s\n", type, pMessage);

	Fatal("%s", message);

	if (flags & VK_DEBUG_REPORT_ERROR_BIT_EXT)
		Info("Validation error encountered!");

	if(flags & VK_DEBUG_REPORT_WARNING_BIT_EXT)
		return VK_FALSE;


	ASSERT(0,"");
	return VK_FALSE;
}

b32 CheckValidationLayerSupport(const char** DebugLayers, s32 ReqCount)
{
	u32 LayerCount;
	vkEnumerateInstanceLayerProperties(&LayerCount, NULL);

	VkLayerProperties AvailableLayers[LayerCount];
	vkEnumerateInstanceLayerProperties(&LayerCount, &AvailableLayers[0]);

	for(s32 i = 0; i<ReqCount; i++)
	{
		b32 LayerFound = false;
		for (u32 z = 0; z<LayerCount; z++)
		{
			if (strcmp(DebugLayers[i], (char*) &AvailableLayers[z]) == 0)
			{
				LayerFound = true;
				break;
			}
		}
		if (!LayerFound)
		{
			return false;
		}
	}
	return true;
}

void RegisterDebugCallback()
{
	if(vkCreateDebugReportCallbackEXT)
	{
		VkDebugReportCallbackCreateInfoEXT DebugReportCallbackCI;
		DebugReportCallbackCI.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
		DebugReportCallbackCI.pNext = NULL;
		DebugReportCallbackCI.flags = VK_DEBUG_REPORT_WARNING_BIT_EXT |
			VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT |
			VK_DEBUG_REPORT_ERROR_BIT_EXT;
		DebugReportCallbackCI.pfnCallback = DebugReportCallback;
		DebugReportCallbackCI.pUserData = NULL;

		VK_CHECK(vkCreateDebugReportCallbackEXT(Instance, &DebugReportCallbackCI, 0, &VulkanDebugCallback));
	}
}

#endif

void RebuildRenderer()
{
	u32 i;
	VK_CHECK(vkDeviceWaitIdle(LogicalDevice));

	VK_CHECK(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(GpuDevice, VkSurface, &SurfaceCapabilities));
	SwchImageSize = SurfaceCapabilities.currentExtent;

	if(SwchImageSize.width == 0 || SwchImageSize.height == 0)
	{
		return; //if window is minimized.
	}

	VkSwapchains[1] = VkSwapchains[0];
	VkSwapchains[0] = VK_NULL_HANDLE;

    	CreateSwapchain(&VkSwapchains[0], &VkSwapchains[1]);

	u32 ImageCount = 0;
	VK_CHECK(vkGetSwapchainImagesKHR(LogicalDevice, VkSwapchains[0], &ImageCount, NULL));
	ASSERT(ImageCount, "Failed to get swapchain image count.");

	ASSERT(VkSwchImages, "Swapchain images unallocated.");

	VK_CHECK(vkGetSwapchainImagesKHR(LogicalDevice, VkSwapchains[0], &ImageCount, &VkSwchImages[0]));

	//Delete incompatible objects.
	for(i = 0; i<SwchImageCount; i++)
	{
		vkDestroyImageView(LogicalDevice, VkSwchImageViews[i], NULL);
	}

	CreateSwapchainImageViews();

	for(i = 0; i < SwchImageCount; i++)
	{
		vkDestroyFramebuffer(LogicalDevice, VkFramebuffers[i], NULL);
	}

	CreateDepthBuffer();
	CreateSwchFrameBuffers();

}

b32 InitVulkan(PFN_vkGetInstanceProcAddr *GetProcAddr, u32 ReqExCount, const char **RequiredExtensions)
{
	u32 i;

	if(!GetProcAddr || !RequiredExtensions || !ReqExCount)
	{
		return false;
	}
	vkGetInstanceProcAddr = *GetProcAddr;

	#define GLOBAL_LEVEL_VULKAN_FUNCTION( name )				\
    	name = (PFN_##name) (vkGetInstanceProcAddr(NULL, #name));	\
    	if(name == NULL)							\
      	{									\
		Fatal("Could not load global Vulkan function: %s", #name);	\
		return false;							\
      	}else								\
      	{Info("Loaded global Vulkan function: %s", #name);}	\

	#define TINY_VULKAN_UPDATE
	#include "tiny_vulkan.h"

	u32 ExtensionCount;
	VK_CHECK(vkEnumerateInstanceExtensionProperties(NULL, &ExtensionCount, NULL));
	VkExtensionProperties InstanceExtensions[ExtensionCount];
	VK_CHECK(vkEnumerateInstanceExtensionProperties(NULL, &ExtensionCount, &InstanceExtensions[0]));

	for(u32 c = 0; c < ReqExCount; c++)
	{
		for(i = 0; i<ExtensionCount; i++)
		{
			if(strstr((char*)&InstanceExtensions[i], RequiredExtensions[c]))
			{
				Info("Using instance extension: %s ", RequiredExtensions[c]);
				goto _continue;
			}
		}
		Debug("Available Extensions: ");
		for(i = 0; i<ExtensionCount; i++)
		{
			Debug("%s", (char*)&InstanceExtensions[i]);
		}
		Fatal("Extension %s  is not supported!", RequiredExtensions[c]);
		return false;
_continue:;
	}

	VkApplicationInfo AppI =
	{
		VK_STRUCTURE_TYPE_APPLICATION_INFO,
		NULL,
		"TinyEngine",
		VK_MAKE_VERSION(1,0,0),
		"TinyEngine",
		VK_MAKE_VERSION(1,0,0),
		VK_MAKE_VERSION(1,0,0)
	};

	VkInstanceCreateInfo InstanceCI;
	InstanceCI.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	InstanceCI.pNext = NULL;
	InstanceCI.flags = 0;
	InstanceCI.pApplicationInfo = &AppI;
	InstanceCI.enabledLayerCount = 0;
	InstanceCI.ppEnabledLayerNames = NULL;
	InstanceCI.enabledExtensionCount = ReqExCount;
	InstanceCI.ppEnabledExtensionNames = &RequiredExtensions[0];

#ifdef TINYENGINE_DEBUG
	const char* DebugLayers[] =
	{
		"VK_LAYER_KHRONOS_validation"
	};
	if(!CheckValidationLayerSupport(DebugLayers, ArrayCount(DebugLayers)))
	{
		Warn("Debug Layers are not found! ");
	}
	else
	{
		InstanceCI.enabledLayerCount = ArrayCount(DebugLayers);
		InstanceCI.ppEnabledLayerNames = DebugLayers;
	}
#endif


	//define custom vulkan allocators
	//allocators = NULL;
	if(VkAllocators)
	{
		void *VkMemory = Tiny_Malloc(8000000); //8MB
		ZInitZone(VkMemory, 8000000, 8, 0);
		VkAllocators->pUserData = NULL;
		VkAllocators->pfnAllocation = VkAlloc;
		VkAllocators->pfnReallocation = VkRealloc;
		VkAllocators->pfnFree = VkFree;
		VkAllocators->pfnInternalAllocation = NULL;
		VkAllocators->pfnInternalFree = NULL;
	}
	VK_CHECK(vkCreateInstance(&InstanceCI, VkAllocators, &Instance));


	#define INSTANCE_LEVEL_VULKAN_FUNCTION( name )				\
    	name = (PFN_##name) (vkGetInstanceProcAddr(Instance, #name));	\
    	if(name == NULL)							\
      	{									\
		Fatal("Could not load instance Vulkan function: %s", #name);	\
		return false;							\
      	}else								\
      	{Info("Loaded instance Vulkan function: %s", #name);}	\

	#define TINY_VULKAN_UPDATE
	#include "tiny_vulkan.h"

	//(Kyryl): For what it takes, do not touch this code !
	//C preprocessor is an evil thing!
	#define INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( name, extension ) \
	for(i = 0; i<ReqExCount; i++) {				\
		if( strstr(RequiredExtensions[i], extension) ) { \
			name = (PFN_##name)vkGetInstanceProcAddr( Instance, #name );	\
			if( name == NULL ){						\
				Warn("Could not load instance-level Vulkan function named: %s", #name);  \
				return false;                                                        \
			}else                                                                       \
			{Info("Loaded function from extension: %s", #name);}		\
		}\
	}  
	#define TINY_VULKAN_UPDATE
	#include "tiny_vulkan.h"

#ifdef TINYENGINE_DEBUG
	RegisterDebugCallback();
#endif

	u32 DeviceCount = 0;
	VK_CHECK(vkEnumeratePhysicalDevices(Instance, &DeviceCount, NULL));
	ASSERT(DeviceCount, "No Gpus enumerated");

	VkPhysicalDevice Devices[DeviceCount];
	VK_CHECK(vkEnumeratePhysicalDevices(Instance, &DeviceCount, &Devices[0]));
	
	u32 DeviceExtensionCount = 0;
	GpuDevice = VK_NULL_HANDLE;
	for(i = 0; i<DeviceCount; i++)
	{
		VK_CHECK(vkEnumerateDeviceExtensionProperties(Devices[i], NULL, &DeviceExtensionCount, NULL));

		VkExtensionProperties ExtensionProperties[DeviceExtensionCount];

		VK_CHECK(vkEnumerateDeviceExtensionProperties(Devices[i], NULL, &DeviceExtensionCount, &ExtensionProperties[0]));

		vkGetPhysicalDeviceFeatures(Devices[i], &DeviceFeatures);
		vkGetPhysicalDeviceProperties(Devices[i], &DeviceProperties);

		if(DeviceProperties.deviceType != VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU && DeviceProperties.deviceType != VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
		{
			continue;
		}
		else
		{
			//Found a Gpu
			u32 Size = (sizeof(VkExtensionProperties)  *DeviceExtensionCount);
			VkDeviceExtensionProperties = (VkExtensionProperties*) Tiny_Malloc(Size);
			memcpy(VkDeviceExtensionProperties, ExtensionProperties, Size);
			DeviceExtPropCount = DeviceExtensionCount;
			GpuDevice = Devices[i];

			Trace("Using Device: %s", DeviceProperties.deviceName);
			break;
		}

	}
	ASSERT(GpuDevice, "Found no matching GpuDevice!");

	//Surface 
	//Is created via platform layer callback.
	SurfaceCallback(&VkSurface); 

	u32 ModesCount = 0;
	VK_CHECK(vkGetPhysicalDeviceSurfacePresentModesKHR(GpuDevice, VkSurface, &ModesCount, NULL));
	ASSERT(ModesCount, "Failed to enumerate presentation modes!");

	VkPresentModeKHR PresentModes[ModesCount];
	VK_CHECK(vkGetPhysicalDeviceSurfacePresentModesKHR(GpuDevice, VkSurface, &ModesCount, &PresentModes[0]));

	//TODO(Kyryl): This is important, need a proper fallback if not listed.
	PresentationMode = VK_PRESENT_MODE_FIFO_KHR;
	for(i = 0; i<ModesCount; i++)
	{
		if(PresentModes[i]==PresentationMode)
		{
			break;
		}
	}
	ASSERT(i != ModesCount, "Presentation mode is not supported!");

	//NOTE(Kyryl): This is necessary for swapchain resize.
	VK_CHECK(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(GpuDevice, VkSurface, &SurfaceCapabilities));
	SwchImageSize = SurfaceCapabilities.currentExtent;
	//End Surface

	//Vulkan Queue init. 
	u32 QFamiliesCount;
	vkGetPhysicalDeviceQueueFamilyProperties(GpuDevice, &QFamiliesCount, NULL);
	ASSERT(QFamiliesCount, "Could not enumerate family queues!");

	VkQueueFamilyProperties QueueFamilies[QFamiliesCount];
	vkGetPhysicalDeviceQueueFamilyProperties(GpuDevice, &QFamiliesCount, &QueueFamilies[0]);

	//(Kyryl): Find a graphics Queue.
	//In case we require move than 1 queue, just copy paste this code with different flags.
	for(i = 0; i<QFamiliesCount; ++i)
	{
		if(QueueFamilies[i].queueCount > 0 && (QueueFamilies[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) == VK_QUEUE_GRAPHICS_BIT)
		{
			break;
		}
	}
	ASSERT(i != QFamiliesCount, "Graphics Queue not found.");
	QueueIndex[0] = i;
	QueuePriority[0] = 1.0f;

	VkBool32 PresentationSupport = VK_FALSE;
	VK_CHECK(vkGetPhysicalDeviceSurfaceSupportKHR(GpuDevice, i, VkSurface, &PresentationSupport));
	ASSERT(PresentationSupport, "Presentation not supported on Queue index %d", i);
	QueueIndex[0] = i;


	//LogicalDevice
	//The reason it's named like this is because we can derive multiple of these 
	//objects from single GpuDevice. Probably the most used object in Vulkan.

	const char *DeviceExtensions[] = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
	for(u32 c = 0; c < ArrayCount(DeviceExtensions); c++)
	{
		for(i = 0; i < DeviceExtPropCount; i++)
		{
			if(strstr(DeviceExtensions[c], (char*)&VkDeviceExtensionProperties[i]))
			{
				Info("Using device extension: %s ", DeviceExtensions[c]);
				goto __continue;
			}
		}
		Debug("Available Extensions: ");
		for(i = 0; i < DeviceExtPropCount; i++)
		{
			Debug("%s", (char*)&VkDeviceExtensionProperties[i]);
		}
		Fatal("Extension %s is not supported by physical device!", DeviceExtensions[c]);
		return false;
__continue:;
	}

	VkDeviceQueueCreateInfo QueueCI[NUM_QUEUES];
	for(i = 0; i<NUM_QUEUES; i++)
	{
		QueueCI[i].sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		QueueCI[i].pNext = NULL;
		QueueCI[i].flags = 0;
		QueueCI[i].queueFamilyIndex = QueueIndex[i];
		QueueCI[i].queueCount = 1;
		QueueCI[i].pQueuePriorities = &QueuePriority[i];
	}

	VkDeviceCreateInfo DeviceCI;
	DeviceCI.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	DeviceCI.pNext = NULL;
	DeviceCI.flags = 0;
	DeviceCI.queueCreateInfoCount = NUM_QUEUES;
	DeviceCI.pQueueCreateInfos = &QueueCI[0];
	DeviceCI.enabledLayerCount = 0;
	DeviceCI.ppEnabledLayerNames = NULL;
	DeviceCI.enabledExtensionCount = ArrayCount(DeviceExtensions);
	DeviceCI.ppEnabledExtensionNames = &DeviceExtensions[0];
	DeviceCI.pEnabledFeatures = &DeviceFeatures;
	VK_CHECK(vkCreateDevice(GpuDevice, &DeviceCI, VkAllocators, &LogicalDevice));

	//End LogicalDevice

	// Load core Vulkan API device-level functions
#define DEVICE_LEVEL_VULKAN_FUNCTION( name )				\
	name = (PFN_##name)vkGetDeviceProcAddr( LogicalDevice, #name );	\
	if( name == NULL ) {						\
		Warn("Could not load device-level Vulkan function named: %s",#name); \
		return false;							\
	}else	{								\
		Info("Loaded device-level function: %s",#name);} \

#define TINY_VULKAN_UPDATE
#include "tiny_vulkan.h"

	// Load device-level functions from enabled extensions
#define DEVICE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( name, extension )	\
	for(i = 0; i<ArrayCount(DeviceExtensions); i++) {				\
		if( strstr(DeviceExtensions[i], extension ) ) { \
			name = (PFN_##name)vkGetDeviceProcAddr( LogicalDevice, #name );	\
			if( name == NULL ) {						\
				Warn("Could not load device-level Vulkan function from extension: %s", #name); \
				return false;							\
			}else{								\
				Info("Loaded device-level function from extension: %s", #name);}	\
		}									\
	}

#define TINY_VULKAN_UPDATE
#include "tiny_vulkan.h"

	vkGetDeviceQueue(LogicalDevice, QueueIndex[0], 0, &VkQueues[0]); //Graphics queue.
	//End Vulkan Queue

	//Swapchain
	SwchImageCount = SurfaceCapabilities.minImageCount + 1;
	if(SurfaceCapabilities.maxImageCount > 0 && SwchImageCount > SurfaceCapabilities.maxImageCount)
	{
		SwchImageCount = SurfaceCapabilities.maxImageCount;
	}
	SwchImageCount += 1;

	VkSwchImageViews = (VkImageView*) Tiny_Malloc(sizeof(VkImageView) * SwchImageCount);

	VkImageUsageFlags TmpImageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT |  VK_IMAGE_USAGE_TRANSFER_DST_BIT;
	SwchImageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT |  VK_IMAGE_USAGE_TRANSFER_DST_BIT;
	SwchImageUsage &= SurfaceCapabilities.supportedUsageFlags;
	ASSERT(TmpImageUsage == SwchImageUsage, "Swapchain images do not support Color | Transfer Attachments");

	SwchTransform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
	if(!(SurfaceCapabilities.supportedTransforms & SwchTransform))
	{
		SwchTransform = SurfaceCapabilities.currentTransform;
	}

	// Enumerate supported swapchain image formats.
	//NOTE(Kyryl): This is default cofig we are seaching for.
	u32 FormatCount = 0;
	VkSurfaceFormatKHR SurfaceFormat;
	SurfaceFormat.format = VK_FORMAT_R8G8B8A8_UNORM;
	SurfaceFormat.colorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;

	VK_CHECK(vkGetPhysicalDeviceSurfaceFormatsKHR(GpuDevice, VkSurface, &FormatCount, NULL));
	ASSERT(FormatCount, "Failed to enumerate swapchain image formats.");

	VkSurfaceFormatKHR SurfaceFormats[FormatCount];
	VK_CHECK(vkGetPhysicalDeviceSurfaceFormatsKHR(GpuDevice, VkSurface, &FormatCount, &SurfaceFormats[0]));

	// Select surface format
	if(FormatCount == 1 && SurfaceFormats[0].format == VK_FORMAT_UNDEFINED)
	{
		SwchImageFormat = SurfaceFormat.format;
		SwchImageColorSpace = SurfaceFormat.colorSpace;
		goto out;
	}
	else
	{
		for(i = 0; i<FormatCount; i++)
		{
			if(SurfaceFormat.format == SurfaceFormats[i].format && SurfaceFormat.colorSpace == SurfaceFormats[i].colorSpace)
			{
				SwchImageFormat = SurfaceFormat.format;
				SwchImageColorSpace = SurfaceFormat.colorSpace;
				goto out;
			}
		}

		for(i = 0; i<FormatCount; i++)
		{
			if( (SurfaceFormat.format == SurfaceFormats[i].format) )
			{
				SwchImageFormat = SurfaceFormat.format;
				SwchImageColorSpace = SurfaceFormats[i].colorSpace;
				Warn("Combination of format and colorspace is not supported. Selecting other colorspace.");
				goto out;
			}
		}
	}
	SwchImageFormat = SurfaceFormats[0].format;
	SwchImageColorSpace = SurfaceFormats[0].colorSpace;
	Warn("Surface format is not supported. Selecting available format - colorspace combination." );
out:;

    	CreateSwapchain(&VkSwapchains[0], &VkSwapchains[1]);

	//Swapchain Images, required for rendering.
	//They are treated as special an unique.
	u32 ImageCount = 0;
	VK_CHECK(vkGetSwapchainImagesKHR(LogicalDevice, VkSwapchains[0], &ImageCount, NULL));
	ASSERT(ImageCount, "Failed to get swapchain image count.");

	VkSwchImages = (VkImage*) Tiny_Malloc(sizeof(VkImage) * ImageCount);

	VK_CHECK(vkGetSwapchainImagesKHR(LogicalDevice, VkSwapchains[0], &ImageCount, &VkSwchImages[0]));

	CreateSwapchainImageViews();

	//End Swapchain

	//RENDER RESOURCES
	VkSemaphoreCreateInfo SemaphoreCI;
	SemaphoreCI.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
	SemaphoreCI.pNext = NULL;
	SemaphoreCI.flags = 0;

	for(i = 0; i < NUM_SEMAPHORES; i++)
	{
		VK_CHECK(vkCreateSemaphore(LogicalDevice, &SemaphoreCI, VkAllocators, &VkWaitSemaphores[i]));
	}

	for(i = 0; i < NUM_SEMAPHORES; i++)
	{
		VK_CHECK(vkCreateSemaphore(LogicalDevice, &SemaphoreCI, VkAllocators, &VkSignalSemaphores[i]));
	}

	VkFenceCreateInfo FenceCI;
	FenceCI.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
	FenceCI.pNext = NULL;
	FenceCI.flags = VK_FENCE_CREATE_SIGNALED_BIT;

	for(i = 0; i < NUM_FENCES; i++)
	{
		VK_CHECK(vkCreateFence(LogicalDevice, &FenceCI, VkAllocators, &VkFences[i]));
	}

	//NOTE(Kyryl): We can have 1 command pool and many buffers
	//or command pool for every command buffer. 
	//I will make command pool for every buffer in case of future multithreading.
	VkCommandPoolCreateInfo CommandPoolCI;
	CommandPoolCI.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
	CommandPoolCI.pNext = NULL;
	CommandPoolCI.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
	CommandPoolCI.queueFamilyIndex = QueueIndex[0]; //graphics queue.

	//NOTE(Kyryl): they are all on graphics queue currently
	//If we need compute queue explicitly then make separate VkComputeCommandPools
	for(i = 0; i<NUM_COMMAND_POOLS; i++)
	{
		VK_CHECK(vkCreateCommandPool(LogicalDevice, &CommandPoolCI, VkAllocators, &VkCommandPools[i]));
	}

	//Very basic setup. VkCommandBuffers holds only primary buffers.
	VkCommandBufferAllocateInfo CommandBufferAI;
	CommandBufferAI.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	CommandBufferAI.pNext = NULL;
	CommandBufferAI.commandPool = VkCommandPools[0];
	CommandBufferAI.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
	CommandBufferAI.commandBufferCount = NUM_COMMAND_BUFFERS;
	VK_CHECK(vkAllocateCommandBuffers(LogicalDevice, &CommandBufferAI, &VkCommandBuffers[0]));

	ASSERT(NUM_COMMAND_BUFFERS > SwchImageCount+1, "More command buffers needed, increase NUM_COMMAND_BUFFERS");


	//MEMORY
	Trace("Reached target: Memory Init");
	vkGetPhysicalDeviceMemoryProperties(GpuDevice, &DeviceMemoryProperties);

	VertexBuffers[0].Size = 20480;
	VertexBuffers[0].Data = VkHostMalloc(VertexBuffers[0].Size, &VertexBuffers[0].Buffer, &VertexBuffers[0].DeviceMemory, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);
	//Note(Kyryl): vertex buffers require no alignment.
	ZInitZone(VertexBuffers[0].Data, VertexBuffers[0].Size, 1, 1);

	IndexBuffers[0].Size = 20480;
	IndexBuffers[0].Data = VkHostMalloc(IndexBuffers[0].Size, &IndexBuffers[0].Buffer, &IndexBuffers[0].DeviceMemory, VK_BUFFER_USAGE_INDEX_BUFFER_BIT);
	// Align to 4 bytes because we allocate both uint16 and uint32
	// index buffers and alignment must match index size
	ZInitZone(IndexBuffers[0].Data, IndexBuffers[0].Size, 4, 2);

	UniformBuffers[0].Size = 20480;
	UniformBuffers[0].Data = VkHostMalloc(UniformBuffers[0].Size, &UniformBuffers[0].Buffer, &UniformBuffers[0].DeviceMemory, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT);
	// Align to 256 bytes (ref spec)
	ZInitZone(UniformBuffers[0].Data, UniformBuffers[0].Size, 256, 3);

	//STAGING BUFFERS
	StagingBuffers[0].Size = 4194304; //4096 * 1024
	StagingBuffers[0].Data = VkHostMalloc(StagingBuffers[0].Size, &StagingBuffers[0].Buffer, &StagingBuffers[0].DeviceMemory,
	VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

	ZInitZone(StagingBuffers[0].Data, StagingBuffers[0].Size, 4, 4);
	ASSERT(NUM_STAGING_BUFFERS < NUM_FENCES - SwchImageCount, "Increase NUM_FENCES");
	ASSERT(NUM_STAGING_BUFFERS < NUM_COMMAND_BUFFERS - SwchImageCount, "Increase NUM_COMMAND_BUFFERS");
	for(i = 0; i < NUM_STAGING_BUFFERS; i++)
	{
		//Dont't mix render sync and staging 
		StagingBuffers[i].CommandBuffer = VkCommandBuffers[SwchImageCount+i];
		StagingBuffers[i].Fence = VkFences[SwchImageCount+i];

		//Set into recording state
		VkCommandBufferBeginInfo CommandBufferBI;
		CommandBufferBI.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		CommandBufferBI.pNext = NULL;
		CommandBufferBI.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT; 
		CommandBufferBI.pInheritanceInfo = NULL;

		VK_MCHECK(vkBeginCommandBuffer(StagingBuffers[i].CommandBuffer, &CommandBufferBI),"vkBeginCommandBuffer failed!");
		VK_CHECK(vkResetFences(LogicalDevice, 1, &StagingBuffers[i].Fence));
	}
	//STAGING BUFFERS


	//End MEMORY

	//SAMPLERS
	VkSamplerCreateInfo SamplerCI;
	SamplerCI.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
	SamplerCI.pNext = NULL;
	SamplerCI.flags = 0;
	SamplerCI.magFilter = VK_FILTER_NEAREST;
	SamplerCI.minFilter = VK_FILTER_NEAREST;
	SamplerCI.mipmapMode = VK_SAMPLER_MIPMAP_MODE_NEAREST;
	SamplerCI.addressModeU = VK_SAMPLER_ADDRESS_MODE_REPEAT;
	SamplerCI.addressModeV = VK_SAMPLER_ADDRESS_MODE_REPEAT;
	SamplerCI.addressModeW = VK_SAMPLER_ADDRESS_MODE_REPEAT;
	SamplerCI.mipLodBias = 0.0f;
	SamplerCI.anisotropyEnable = 0;
	SamplerCI.maxAnisotropy = 1.0f;
	SamplerCI.compareEnable = 0;
	SamplerCI.compareOp = 0;
	SamplerCI.minLod = 0;
	SamplerCI.maxLod = 0.25f;
	SamplerCI.borderColor = VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK;
	SamplerCI.unnormalizedCoordinates = VK_FALSE;

	VK_CHECK(vkCreateSampler(LogicalDevice, &SamplerCI, NULL, &PointSampler));
	//SAMPLERS

	//DESCRIPTOR SETS
	//NOTE(Kyryl): 
	//This is a very commonly used objects and through this we can access resources like
	//UBOs texture samplers and much more! Think of descriptor set a pointer object.
	VkDescriptorPoolSize PoolSize[2];
	PoolSize[0].type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC;
	PoolSize[0].descriptorCount = 32;
	PoolSize[1].type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
	PoolSize[1].descriptorCount = 2048;

	VkDescriptorPoolCreateInfo DescriptorPoolCI;
	DescriptorPoolCI.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
	DescriptorPoolCI.pNext = NULL;
	DescriptorPoolCI.flags = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
	DescriptorPoolCI.maxSets = 2048 + 32;
	DescriptorPoolCI.poolSizeCount = 2;
	DescriptorPoolCI.pPoolSizes = PoolSize;
	VK_CHECK(vkCreateDescriptorPool(LogicalDevice, &DescriptorPoolCI, VkAllocators, &DescriptorPool));

	//NOTE(Kyryl):
	//There are many ways to do this and lay out the objects. 
	//Through experience I think this is the most flexible way.
	//This covers a lot of need cases, but if more needed, always add here.

	//Vubo = vertex uniform buffer object
	VkDescriptorSetLayoutBinding VuboSLB;
	VuboSLB.binding = 0;
	VuboSLB.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC;
	VuboSLB.descriptorCount = 1;
	VuboSLB.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;
	VuboSLB.pImmutableSamplers = NULL;

	//Fubo = fragment uniform buffer object
	VkDescriptorSetLayoutBinding FuboSLB;
	FuboSLB.binding = 0;
	FuboSLB.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC;
	FuboSLB.descriptorCount = 1;
	FuboSLB.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
	FuboSLB.pImmutableSamplers = NULL;

	//Fso = fragment sampler object
	VkDescriptorSetLayoutBinding FsoSLB;
	FsoSLB.binding = 0;
	FsoSLB.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
	FsoSLB.descriptorCount = 1;
	FsoSLB.pImmutableSamplers = NULL;
	FsoSLB.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;

	VkDescriptorSetLayoutCreateInfo DescriptorSetLayoutCI;
	DescriptorSetLayoutCI.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
	DescriptorSetLayoutCI.pNext = NULL;
	DescriptorSetLayoutCI.flags = 0;
	DescriptorSetLayoutCI.bindingCount = 1;

	DescriptorSetLayoutCI.pBindings = &VuboSLB;
	VK_CHECK(vkCreateDescriptorSetLayout(LogicalDevice, &DescriptorSetLayoutCI, VkAllocators, &VertUniformDescriptorSetLayout));
	DescriptorSetLayoutCI.pBindings = &FuboSLB;
	VK_CHECK(vkCreateDescriptorSetLayout(LogicalDevice, &DescriptorSetLayoutCI, VkAllocators, &FragUniformDescriptorSetLayout));
	DescriptorSetLayoutCI.pBindings = &FsoSLB;
	VK_CHECK(vkCreateDescriptorSetLayout(LogicalDevice, &DescriptorSetLayoutCI, VkAllocators, &FragSamplerDescriptorSetLayout));

	//Allocate and write descriptor sets. 

	VkDescriptorSetAllocateInfo DescriptorSetAI;
	DescriptorSetAI.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
	DescriptorSetAI.pNext = NULL;
	DescriptorSetAI.descriptorPool = DescriptorPool;
	DescriptorSetAI.descriptorSetCount = 1;

	DescriptorSetAI.pSetLayouts = &VertUniformDescriptorSetLayout;
	vkAllocateDescriptorSets(LogicalDevice, &DescriptorSetAI, &VertUniformDescriptorSet);

	DescriptorSetAI.pSetLayouts = &FragUniformDescriptorSetLayout;
	vkAllocateDescriptorSets(LogicalDevice, &DescriptorSetAI, &FragUniformDescriptorSet);

	DescriptorSetAI.pSetLayouts = &FragSamplerDescriptorSetLayout;
	vkAllocateDescriptorSets(LogicalDevice, &DescriptorSetAI, &FragSamplerDescriptorSet);

	VkDescriptorBufferInfo DescriptorBI;
	DescriptorBI.offset = 0;
	DescriptorBI.range = MAX_UNIFORM_ALLOC;

	VkWriteDescriptorSet WriteDS;
	WriteDS.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
	WriteDS.pNext = NULL;
	WriteDS.dstBinding = 0;
	WriteDS.dstArrayElement = 0;
	WriteDS.descriptorCount = 1;
	WriteDS.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC;
	WriteDS.pImageInfo = NULL;
	WriteDS.pBufferInfo = &DescriptorBI;
	WriteDS.pTexelBufferView = NULL;

	DescriptorBI.buffer = UniformBuffers[0].Buffer;
	WriteDS.dstSet = VertUniformDescriptorSet;
	vkUpdateDescriptorSets(LogicalDevice, 1, &WriteDS, 0, NULL);

	DescriptorBI.buffer = UniformBuffers[0].Buffer;
	WriteDS.dstSet = FragUniformDescriptorSet;
	vkUpdateDescriptorSets(LogicalDevice, 1, &WriteDS, 0, NULL);

	//Create a 2d texture to serve as pixel buffer. 
	//Implements an ability to write pixels directly to the screen.
	//PixelImageView = CreateImageView(SwchImageFormat, VK_IMAGE_VIEW_TYPE_2D, PixelImage);

	texture_t PixelTexture;
	PixelTexture.Data = Tiny_Malloc(SwchImageSize.width * SwchImageSize.height);
	PixelTexture.Width = SwchImageSize.width;
	PixelTexture.Height = SwchImageSize.height;
	PixelTexture.ImageType = VK_IMAGE_TYPE_2D;
	PixelTexture.ImageViewType = VK_IMAGE_VIEW_TYPE_2D;
	PixelTexture.Format = SwchImageFormat;
	PixelTexture.Usage = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT;

	CreateTexture(&PixelTexture);

	VkDescriptorImageInfo DescriptorII;
	DescriptorII.sampler = PointSampler;
	DescriptorII.imageView = PixelTexture.ImageView; 
	DescriptorII.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;

	WriteDS.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
	WriteDS.pBufferInfo = NULL; //this is not a uniform buffer. 
	WriteDS.pImageInfo = &DescriptorII;
	WriteDS.dstSet = FragSamplerDescriptorSet;
	vkUpdateDescriptorSets(LogicalDevice, 1, &WriteDS, 0, NULL);

	UploadTexture(&PixelTexture);

	//End DESCRIPTOR SETS

	//DEPTH BUFFER

	// Find depth format
	VkFormatProperties FormatProperties;
	vkGetPhysicalDeviceFormatProperties(GpuDevice, VK_FORMAT_X8_D24_UNORM_PACK32, &FormatProperties);
	b32 x8_d24_support = (FormatProperties.optimalTilingFeatures & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT) != 0;
	vkGetPhysicalDeviceFormatProperties(GpuDevice, VK_FORMAT_D32_SFLOAT, &FormatProperties);
	b32 d32_support = (FormatProperties.optimalTilingFeatures & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT) != 0;

	DepthFormat = VK_FORMAT_D16_UNORM;
	if (x8_d24_support)
	{
		Trace("Using X8_D24 depth buffer format");
		DepthFormat = VK_FORMAT_X8_D24_UNORM_PACK32;
	}
	else if(d32_support)
	{
		Trace("Using D32 depth buffer format");
		DepthFormat = VK_FORMAT_D32_SFLOAT;
	}

	CreateDepthBuffer();

	//End DEPTH BUFFER

	//Renderpass
	VkAttachmentDescription Attachments[2];
	Attachments[0].flags = VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT;
	Attachments[0].format = SwchImageFormat;
	Attachments[0].samples = VK_SAMPLE_COUNT_1_BIT;
	Attachments[0].loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
	Attachments[0].storeOp = VK_ATTACHMENT_STORE_OP_STORE;
	Attachments[0].stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
	Attachments[0].stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
	Attachments[0].initialLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
	Attachments[0].finalLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

	Attachments[1].flags = VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT;
	Attachments[1].samples = VK_SAMPLE_COUNT_1_BIT;
	Attachments[1].format = DepthFormat;
	Attachments[1].loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
	Attachments[1].storeOp = VK_ATTACHMENT_STORE_OP_STORE;
	Attachments[1].stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
	Attachments[1].stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
	Attachments[1].initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
	Attachments[1].finalLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

	VkAttachmentReference colorAttachment;
	colorAttachment.attachment = 0;
	colorAttachment.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

	VkAttachmentReference depthAttachment;
	depthAttachment.attachment = 1;
	depthAttachment.layout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

	VkSubpassDescription Subpass[1];
	Subpass[0].flags = 0;
	Subpass[0].pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
	Subpass[0].inputAttachmentCount = 0;
	Subpass[0].pInputAttachments = NULL;
	Subpass[0].colorAttachmentCount = 1;
	Subpass[0].pColorAttachments = &colorAttachment;
	Subpass[0].pResolveAttachments = NULL;
	Subpass[0].pDepthStencilAttachment = &depthAttachment;
	Subpass[0].preserveAttachmentCount = 0;
	Subpass[0].pPreserveAttachments = NULL;

	VkRenderPassCreateInfo RenderPassCI;
	RenderPassCI.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
	RenderPassCI.pNext = NULL;
	RenderPassCI.flags = 0;
	RenderPassCI.attachmentCount = 2;
	RenderPassCI.pAttachments = Attachments;
	RenderPassCI.subpassCount = 1;
	RenderPassCI.pSubpasses = &Subpass[0];
	RenderPassCI.dependencyCount = 0;
	RenderPassCI.pDependencies = NULL;

	VK_CHECK(vkCreateRenderPass(LogicalDevice, &RenderPassCI, 0, &VkRenderPasses[0]));

	CreateSwchFrameBuffers();

	//End Renderpass

	//SHADERS & PIPELINE

	//TODO:Implement pipeline cache.

#ifdef HEX_SHADERS
#include "Vbasic.h"
#include "Fbasic.h"
	LoadHexShader(Vbasic, ArrayCount(Vbasic)*sizeof(u32));
	LoadHexShader(Fbasic, ArrayCount(Fbasic)*sizeof(u32));
#else
	LoadShader("../source/shaders/Vbasic.spv");
	LoadShader("../source/shaders/Fbasic.spv");
#endif

	//The most simple layout.
	VkPipelineLayoutCreateInfo PipelineLayoutCI;
	PipelineLayoutCI.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
	PipelineLayoutCI.pNext = NULL;
	PipelineLayoutCI.flags = 0;
	PipelineLayoutCI.setLayoutCount = 0;
	PipelineLayoutCI.pSetLayouts = NULL;
	PipelineLayoutCI.pushConstantRangeCount = 0;
	PipelineLayoutCI.pPushConstantRanges = NULL;
	VK_CHECK(vkCreatePipelineLayout(LogicalDevice, &PipelineLayoutCI, VkAllocators, &VkPipelineLayouts[0]));

	PipelineLayoutCI.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
	PipelineLayoutCI.pNext = NULL;
	PipelineLayoutCI.flags = 0;
	PipelineLayoutCI.setLayoutCount = 0;
	PipelineLayoutCI.pSetLayouts = NULL;
	PipelineLayoutCI.pushConstantRangeCount = 0;
	PipelineLayoutCI.pPushConstantRanges = NULL;
	VK_CHECK(vkCreatePipelineLayout(LogicalDevice, &PipelineLayoutCI, VkAllocators, &VkPipelineLayouts[0]));

	CreateBasicShaderPipeline(VK_POLYGON_MODE_FILL);

	//End SHADERS & PIPELINE

	//End RENDER RESOURCES

	Trace("Reached target: (Init) Final Step");

	//POST INIT
	//(Kyryl): Prepares vulkan objects used at real time rendering.
	PostInit();

	//End POST INIT
	return true;

}

void PostInit()
{
	//Sanity checks
	ASSERT(MAX_FRAMES_IN_FLIGHT < NUM_SEMAPHORES, "MAX_FRAMES_IN_FLIGHT > NUM_SEMAPHORES");
	ASSERT(MAX_FRAMES_IN_FLIGHT < NUM_FENCES, "MAX_FRAMES_IN_FLIGHT > NUM_FENCES");

	CurrentFrame = 0;

	PipelineStageFlags = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT;
	ColorValue.float32[0] = 0;
	ColorValue.float32[1] = 0;
	ColorValue.float32[2] = 0;
	ColorValue.float32[3] = 1;
	VkClearValues[0].color = ColorValue;
	VkClearValues[1].depthStencil.depth = 1.0f;
	VkClearValues[1].depthStencil.stencil = 0;

	ImageSubResourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	ImageSubResourceRange.baseMipLevel = 0;
	ImageSubResourceRange.levelCount = VK_REMAINING_MIP_LEVELS;
	ImageSubResourceRange.baseArrayLayer = 0;
	ImageSubResourceRange.layerCount = VK_REMAINING_ARRAY_LAYERS;

	BeginRenderMemBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
	BeginRenderMemBarrier.pNext = NULL;
	BeginRenderMemBarrier.srcAccessMask = VK_ACCESS_MEMORY_READ_BIT;
	BeginRenderMemBarrier.dstAccessMask = 0;
	BeginRenderMemBarrier.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
	BeginRenderMemBarrier.newLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
	BeginRenderMemBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
	BeginRenderMemBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
	BeginRenderMemBarrier.subresourceRange = ImageSubResourceRange;

	EndRenderMemBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
	EndRenderMemBarrier.pNext = NULL;
	EndRenderMemBarrier.srcAccessMask = VK_ACCESS_MEMORY_READ_BIT;
	EndRenderMemBarrier.dstAccessMask = 0;
	EndRenderMemBarrier.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
	EndRenderMemBarrier.newLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
	EndRenderMemBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
	EndRenderMemBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
	EndRenderMemBarrier.subresourceRange = ImageSubResourceRange;

	SubmitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
	SubmitInfo.pNext = NULL;
	SubmitInfo.waitSemaphoreCount = 1;
	SubmitInfo.pWaitDstStageMask = &PipelineStageFlags;
	SubmitInfo.commandBufferCount = 1;
	SubmitInfo.signalSemaphoreCount = 1;

	PresentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
	PresentInfo.pNext = NULL;
	PresentInfo.waitSemaphoreCount = 1;
	PresentInfo.swapchainCount = 1;
	PresentInfo.pImageIndices = &ImageIndex;
	PresentInfo.pResults = NULL;
}

void VkBeginRendering()
{
	VkResult result;
	vkResetFences(LogicalDevice, 1, &VkFences[CurrentFrame]);

	//tell hardware to not wait more than 1 second.
wait:
	result = vkAcquireNextImageKHR(LogicalDevice, VkSwapchains[0], 1000000000, VkSignalSemaphores[CurrentFrame], VK_NULL_HANDLE, &ImageIndex);
	switch( result )
	{
	case VK_SUCCESS:
		break;
	case VK_SUBOPTIMAL_KHR:
		Info("VkBeginRendering: VK_SUBOPTIMAL_KHR");
		break;
	case VK_TIMEOUT:
		Info("VK_TIMEOUT");
		goto wait;
	case VK_ERROR_OUT_OF_DATE_KHR:
		Info("VkBeginRendering: VK_ERROR_OUT_OF_DATE_KHR");
		RebuildRenderer();
		goto wait;
	default:
		VK_CHECK(result);
		return;
	}

	while(SubmitStagingBuffer()){/*nothing*/};

	CommandBuffer = VkCommandBuffers[ImageIndex];

	VkCommandBufferBeginInfo CommandBufferBI;
	CommandBufferBI.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
	CommandBufferBI.pNext = NULL;
	CommandBufferBI.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT; 
	CommandBufferBI.pInheritanceInfo = NULL;

	VK_MCHECK(vkBeginCommandBuffer(CommandBuffer, &CommandBufferBI),"vkBeginCommandBuffer failed!");

	VkRect2D RenderArea;
	RenderArea.offset.x = 0;
	RenderArea.offset.y = 0;
	RenderArea.extent.width = SwchImageSize.width;
	RenderArea.extent.height = SwchImageSize.height;

	BeginRenderMemBarrier.image = VkSwchImages[ImageIndex];

	vkCmdPipelineBarrier(CommandBuffer, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
	                     0, 0, NULL, 0, NULL, 1, &BeginRenderMemBarrier);

	VkRenderPassBeginInfo RenderPassBI;
	RenderPassBI.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
	RenderPassBI.pNext = NULL;
	RenderPassBI.renderPass = VkRenderPasses[0];
	RenderPassBI.framebuffer = VkFramebuffers[ImageIndex];
	RenderPassBI.renderArea = RenderArea;
	RenderPassBI.clearValueCount = 2;
	RenderPassBI.pClearValues = VkClearValues;

	vkCmdBeginRenderPass(CommandBuffer, &RenderPassBI, VK_SUBPASS_CONTENTS_INLINE);

	VkViewport Viewport;
	Viewport.x = 0;
	Viewport.y = 0;
	Viewport.width = SwchImageSize.width;
	Viewport.height = SwchImageSize.height;
	Viewport.minDepth = 0;
	Viewport.maxDepth = 1;

	vkCmdSetViewport(CommandBuffer, 0, 1, &Viewport);
	vkCmdSetScissor(CommandBuffer, 0, 1, &RenderArea);
}

void VkEndRendering()
{
	VkResult result;
	vkCmdEndRenderPass(CommandBuffer);

	//transition swapchain image format
	EndRenderMemBarrier.image = VkSwchImages[ImageIndex];

	vkCmdPipelineBarrier(CommandBuffer, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
	                     0, 0, NULL, 0, NULL, 1, &EndRenderMemBarrier);


	SubmitInfo.pWaitSemaphores = &VkSignalSemaphores[CurrentFrame];
	SubmitInfo.pCommandBuffers = &CommandBuffer;
	SubmitInfo.pSignalSemaphores = &VkWaitSemaphores[CurrentFrame];
	PresentInfo.pWaitSemaphores = &VkWaitSemaphores[CurrentFrame];
	PresentInfo.pSwapchains = &VkSwapchains[0];

	VK_CHECK(vkEndCommandBuffer(CommandBuffer));
	VK_CHECK(vkQueueSubmit(VkQueues[0], 1, &SubmitInfo, VkFences[CurrentFrame]));
	result = vkQueuePresentKHR(VkQueues[0], &PresentInfo);
	vkWaitForFences(LogicalDevice, 1, &VkFences[CurrentFrame], VK_TRUE, UINT64_MAX);

	switch(result)
	{
	case VK_SUCCESS:
		CurrentFrame = (CurrentFrame + 1) % MAX_FRAMES_IN_FLIGHT;
		return;
	case VK_ERROR_OUT_OF_DATE_KHR:
		Info("VkEndRendering: VK_ERROR_OUT_OF_DATE_KHR");
		RebuildRenderer();
		return; 
	default:
		VK_CHECK(result);
		return;
	}

}

void DrawBasic(u32 VertexCount, Vertex *VertexBuffer, u32 IndexCount, u32 *IndexBuffer)
{
	u8 *Verts = (u8*) ZMalloc(VertexCount*sizeof(Vertex), 1);	
	u8 *Index = (u8*) ZMalloc(IndexCount*sizeof(u32), 2);	
	VkDeviceSize VOffset = Verts - (u8*) VertexBuffers[0].Data;
	VkDeviceSize IOffset = Index - (u8*) IndexBuffers[0].Data;
	memcpy(Verts, &VertexBuffer[0], VertexCount*sizeof(Vertex));
	memcpy(Index, &IndexBuffer[0], IndexCount*sizeof(u32));
	vkCmdBindVertexBuffers(CommandBuffer, 0, 1, &VertexBuffers[0].Buffer, &VOffset);
	vkCmdBindIndexBuffer(CommandBuffer, IndexBuffers[0].Buffer, IOffset, VK_INDEX_TYPE_UINT32);
	vkCmdBindPipeline(CommandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, VkPipelines[0]);
	vkCmdDrawIndexed(CommandBuffer, IndexCount, 1, 0, 0, 0);


	ZFree(Verts, 1); 
	ZFree(Index, 2);
}

#endif
