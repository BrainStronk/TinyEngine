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

#define VK_NO_PROTOTYPES
#include "vulkan_core.h"
#include "log.h"
#include "tinyengine_types.h"


/*
This file will contain platform intedependent vulkan code
*/

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

const char* GetVulkanResultString(VkResult result);

#ifdef TINYENGINE_DEBUG
#   define ASSERT(condition, message, ...) \
	do { \
		if (! (condition)) \
		{ \
			Fatal(message, ##__VA_ARGS__);\
			FILE *File = fopen(__FILE__, "r");\
			if(File)\
			{\
				int count = 0;\
				char line[1024];\
				LogNewLine = false;\
				LogExtra = false;\
				while(fgets(line, 1024, File)) \
				{\
					count++;\
					if(count >= (__LINE__ - 5) && count <= (__LINE__ + 5))\
					{ Trace("%d %s", count, &line[0]);}\
				}\
			}\
			LogExtra = true;\
			LogNewLine = true;\
			Fatal("Assertion %s failed in, %s line: %d ", #condition, __FILE__, __LINE__);\
			char Buf[10];					\
			fgets(Buf, 10, stdin); \
			exit(1); \
		} \
	} while (false)

#define VK_CHECK(call)\
	do {\
		ASSERT(call == VK_SUCCESS,"VK_CHECK: %s", GetVulkanResultString(call));\
	} while (false)

#else
#define ASSERT(condition, message, ...)
#define VK_CHECK(call)
#endif

//VULKAN GLOBALS
//-----------------------------------------------------
VkAllocationCallbacks Allocator;
VkAllocationCallbacks* VkAllocators = NULL;//&Allocator;
VkInstance Instance;

//Gpu init:
VkDevice LogicalDevice;
VkPhysicalDevice GpuDevice;
VkExtensionProperties* DeviceExtensionProperties;
u32 DeviceExtPropCount;
VkPhysicalDeviceProperties DeviceProperties;
VkPhysicalDeviceFeatures DeviceFeatures;

//Gpu Queues
#define NUM_QUEUES 1
VkQueue Queues[NUM_QUEUES];
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
VkImage* SwchImages;
u32 SwchImageCount;
VkColorSpaceKHR SwchImageColorSpace;
VkFormat SwchImageFormat;
VkSwapchainKHR VkSwapchains[10];

//----------------------------------------------------_

const char* GetVulkanResultString(VkResult result)
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

void ClampSizeOfSwapchainImages(u32 x, u32 y)
{
	if( x < SurfaceCapabilities.minImageExtent.width )
	{
		SwchImageSize.width = SurfaceCapabilities.minImageExtent.width;
	}
	else if( x > SurfaceCapabilities.maxImageExtent.width )
	{
		SwchImageSize.width = SurfaceCapabilities.maxImageExtent.width;
	}
	if( y < SurfaceCapabilities.minImageExtent.height )
	{
		SwchImageSize.height = SurfaceCapabilities.minImageExtent.height;
	}
	else if( y > SurfaceCapabilities.maxImageExtent.height )
	{
		SwchImageSize.height = SurfaceCapabilities.maxImageExtent.height;
	}
}

void CreateSwapchain(VkSwapchainKHR* Swapchain, VkSwapchainKHR* OldSwapchain)
{
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

b32 InitVulkan(PFN_vkGetInstanceProcAddr* GetProcAddr, void(SurfaceCallback(VkSurfaceKHR*)))
{
	u32 i;
	const char *RequiredExtensions[] =
	{
		VK_KHR_SURFACE_EXTENSION_NAME,
		VK_KHR_XLIB_SURFACE_EXTENSION_NAME,
#ifdef TINYENGINE_DEBUG
		VK_EXT_DEBUG_REPORT_EXTENSION_NAME
#endif
	};

	ASSERT(SwchImageSize.width, "Please call SetSizeOfSwapchainImages before attemting init.");

	if(!GetProcAddr || !SurfaceCallback)
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

	for(u32 c = 0; c < ArrayCount(RequiredExtensions); c++)
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
	InstanceCI.enabledExtensionCount = ArrayCount(RequiredExtensions);
	InstanceCI.ppEnabledExtensionNames = &RequiredExtensions[0];


	//define custom vulkan allocators
	//allocators = nullptr;
	if(VkAllocators)
	{
		//allocators->pUserData = nullptr;
		//allocators->pfnAllocation =
		//allocators->pfnReallocation =
		//allocators->pfnFree =
		//allocators->pfnInternalAllocation = nullptr;
		//allocators->pfnInternalFree = nullptr;
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
	for(i = 0; i<ArrayCount(RequiredExtensions); i++) {				\
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
			int size = (sizeof(VkExtensionProperties) * DeviceExtensionCount);
			DeviceExtensionProperties = (VkExtensionProperties*) malloc(size);
			memcpy(DeviceExtensionProperties, ExtensionProperties, size);
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
	ClampSizeOfSwapchainImages(SwchImageSize.width, SwchImageSize.height);
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

	const char* DeviceExtensions[] = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
	for(int c = 0; c < ArrayCount(DeviceExtensions); c++)
	{
		for(i = 0; i < DeviceExtPropCount; i++)
		{
			if(strstr(DeviceExtensions[c], (char*)&DeviceExtensionProperties[i]))
			{
				Info("Using device extension: %s ", DeviceExtensions[c]);
				goto __continue;
			}
		}
		Debug("Available Extensions: ");
		for(i = 0; i < DeviceExtPropCount; i++)
		{
			Debug("%s", (char*)&DeviceExtensionProperties[i]);
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

	vkGetDeviceQueue(LogicalDevice, QueueIndex[0], 0, &Queues[0]); //Graphics queue.
	//End Vulkan Queue

	//Swapchain
	SwchImageCount = SurfaceCapabilities.maxImageCount + 1;

	VkImageUsageFlags TmpImageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT |  VK_IMAGE_USAGE_TRANSFER_DST_BIT;
	SwchImageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT |  VK_IMAGE_USAGE_TRANSFER_DST_BIT;
	SwchImageUsage &= SurfaceCapabilities.supportedUsageFlags;
	ASSERT(TmpImageUsage == SwchImageUsage, "Swapchain images do not support Color | Transfer attachments");

	SwchTransform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
	if(!SurfaceCapabilities.supportedTransforms & SwchTransform)
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
	uint32_t ImageCount = 0;
	VK_CHECK(vkGetSwapchainImagesKHR(LogicalDevice, VkSwapchains[0], &ImageCount, NULL));
	ASSERT(ImageCount, "Failed to get swapchain image count.");

	SwchImages = (VkImage*) malloc(sizeof(VkImage) * ImageCount);

	VK_CHECK(vkGetSwapchainImagesKHR(LogicalDevice, VkSwapchains[0], &ImageCount, &SwchImages[0]));

	//End Swapchain

	return true;


}

#endif
