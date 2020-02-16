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

//FORWARD DECLARATIONS
const char *GetVulkanResultString(VkResult result);
s32 MemoryTypeFromProperties(u32 type_bits, VkFlags requirements_mask, VkFlags preferred_mask);
//--------------------

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

#define VK_MCHECK(call, message)\
	do {\
		ASSERT(call == VK_SUCCESS,"VK_MCHECK: %s | %s", GetVulkanResultString(call), message);\
	} while (false)

#else
#define ASSERT(condition, message, ...)
#define VK_CHECK(call)
#endif

//VULKAN GLOBALS
//-----------------------------------------------------
VkAllocationCallbacks Allocator;
VkAllocationCallbacks *VkAllocators = NULL;//&Allocator;
VkInstance Instance;

//Gpu init:
VkDevice LogicalDevice;
VkPhysicalDevice GpuDevice;
VkExtensionProperties *DeviceExtensionProperties;
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
VkImage *SwchImages;
u32 SwchImageCount;
VkColorSpaceKHR SwchImageColorSpace;
VkFormat SwchImageFormat;
VkSwapchainKHR VkSwapchains[10];
VkImageView* SwchImageViews;

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
VkSemaphore VkSemaphores[NUM_SEMAPHORES];
VkFence VkFences[NUM_FENCES];
VkRenderPass VkRenderPasses[NUM_RENDERPASSES];
VkFramebuffer VkFramebuffers[NUM_FRAMEBUFFERS];
VkImageView VkImageViews[NUM_IMAGEVIEWS];
VkPipeline VkPipelines[NUM_PIPELINES];
VkPipelineLayout VkPipelineLayouts[NUM_PIPELINE_LAYOUTS];
VkCommandPool VkCommandPools[NUM_COMMAND_POOLS];
VkCommandBuffer VkCommandBuffers[NUM_COMMAND_BUFFERS];

//DEPTH
VkImage DepthBuffer;
VkImageView DepthBufferView;
VkDeviceMemory DepthBufferMemory;
VkFormat DepthFormat;

//MEMORY
#define NUM_MAXALLOC_VBO 100
#define NUM_VBO_BUFFERS 10
//----------------------------------------------------
VkPhysicalDeviceMemoryProperties DeviceMemoryProperties;

u32 VboAllocCount;
VkDeviceMemory VboDeviceMemory[NUM_MAXALLOC_VBO];
typedef struct vbo_t
{
	VkBuffer Buffer;
	u32 Offset;
	void *Data;
}vbo_t;
vbo_t VertexBuffers[NUM_VBO_BUFFERS];

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
	memblock_t Blocklist;	// start / end cap for linked list
	memblock_t *Rover;
} memzone_t;

memzone_t *Mainzone[3];
int Zsizes[3];
//------------------------------SGM

//--------------------------------------MEMORY

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

void CreateSwapchain(VkSwapchainKHR *Swapchain, VkSwapchainKHR *OldSwapchain)
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
		SwchImageViewCI.image = SwchImages[i];
		VK_CHECK(vkCreateImageView(LogicalDevice, &SwchImageViewCI, 0, &SwchImageViews[i]));
	}
}

VkImage Create2DImage(VkFormat format, VkImageUsageFlags usage, int w, int h)
{
	VkImage Img;
	VkImageCreateInfo ImageCI;
	memset(&ImageCI, 0, sizeof(ImageCI));
	ImageCI.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
	ImageCI.imageType = VK_IMAGE_TYPE_2D;
	ImageCI.format = format;
	ImageCI.extent.width = w;
	ImageCI.extent.height = h;
	ImageCI.extent.depth = 1;
	ImageCI.mipLevels = 1;
	ImageCI.arrayLayers = 1;
	ImageCI.samples = VK_SAMPLE_COUNT_1_BIT;
	ImageCI.tiling = VK_IMAGE_TILING_OPTIMAL;
	ImageCI.usage = usage;
	ImageCI.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
	ImageCI.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;

	VK_CHECK(vkCreateImage(LogicalDevice, &ImageCI, NULL, &Img));
	return Img;
}

void DestroyDepthBuffer()
{
	vkDestroyImage(LogicalDevice, DepthBuffer, NULL);
	vkFreeMemory(LogicalDevice, DepthBufferMemory, NULL);
	vkDestroyImageView(LogicalDevice, DepthBufferView, NULL);
}

void CreateDepthBuffer()
{
	Trace("Creating depth buffer");

	if(DepthBuffer)
	{
		DestroyDepthBuffer();
	}

	DepthBuffer = Create2DImage(DepthFormat, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT, SwchImageSize.width, SwchImageSize.height);

	VkMemoryRequirements MemoryRequirements;
	vkGetImageMemoryRequirements(LogicalDevice, DepthBuffer, &MemoryRequirements);

	VkMemoryDedicatedAllocateInfoKHR DedicatedAI;
	DedicatedAI.sType = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO_KHR;
	DedicatedAI.pNext = NULL;
	DedicatedAI.image = DepthBuffer;
	DedicatedAI.buffer = VK_NULL_HANDLE;

	VkMemoryAllocateInfo MemoryAI;
	MemoryAI.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
	MemoryAI.pNext = NULL;
	MemoryAI.allocationSize = MemoryRequirements.size;
	MemoryAI.memoryTypeIndex = MemoryTypeFromProperties(MemoryRequirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, 0);

	VK_CHECK(vkAllocateMemory(LogicalDevice, &MemoryAI, NULL, &DepthBufferMemory));
	VK_CHECK(vkBindImageMemory(LogicalDevice, DepthBuffer, DepthBufferMemory, 0));

	VkImageViewCreateInfo DepthBufferImageViewCI;
	DepthBufferImageViewCI.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
	DepthBufferImageViewCI.pNext = NULL;
	DepthBufferImageViewCI.flags = 0;
	DepthBufferImageViewCI.image = DepthBuffer;
	DepthBufferImageViewCI.viewType = VK_IMAGE_VIEW_TYPE_2D;
	DepthBufferImageViewCI.format = VK_FORMAT_D32_SFLOAT;
	DepthBufferImageViewCI.components.r = 0; 
	DepthBufferImageViewCI.components.g = 0; 
	DepthBufferImageViewCI.components.b = 0; 
	DepthBufferImageViewCI.components.a = 0; 
	DepthBufferImageViewCI.subresourceRange.aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT;
	DepthBufferImageViewCI.subresourceRange.baseMipLevel = 0;
	DepthBufferImageViewCI.subresourceRange.levelCount = 1;
	DepthBufferImageViewCI.subresourceRange.baseArrayLayer = 0;
	DepthBufferImageViewCI.subresourceRange.layerCount = 1;

	VK_CHECK(vkCreateImageView(LogicalDevice, &DepthBufferImageViewCI, NULL, &DepthBufferView));
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
//There will be one huge buffer, so in theory this function
//should be called only once, but may be used in case of scarcity
void *VboMalloc(int size, VkBuffer *buffer)
{
	ASSERT(VboAllocCount < NUM_MAXALLOC_VBO, "VBO MAXALLOC");

	VkBufferCreateInfo BufferCI;
	BufferCI.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
	BufferCI.pNext = NULL;
	BufferCI.flags = 0;
	BufferCI.size = size;
	BufferCI.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
	BufferCI.sharingMode = 0;
	BufferCI.queueFamilyIndexCount = 0;
	BufferCI.pQueueFamilyIndices = NULL;

	VK_MCHECK(vkCreateBuffer(LogicalDevice, &BufferCI, VkAllocators, buffer), "vkCreateBuffer failed!");

	VkMemoryRequirements MemoryRequirements;
	vkGetBufferMemoryRequirements(LogicalDevice, *buffer, &MemoryRequirements);

	s32 AlignMod = MemoryRequirements.size % MemoryRequirements.alignment;
	s32 AlignedSize = ((MemoryRequirements.size % MemoryRequirements.alignment) == 0)
	                         ? MemoryRequirements.size
	                         : (MemoryRequirements.size + MemoryRequirements.alignment - AlignMod);

	VkMemoryAllocateInfo MemoryAI;
	MemoryAI.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
	MemoryAI.pNext = NULL;
	MemoryAI.allocationSize = AlignedSize;
	MemoryAI.memoryTypeIndex = MemoryTypeFromProperties(MemoryRequirements.memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, VK_MEMORY_PROPERTY_HOST_CACHED_BIT);

	VK_MCHECK(vkAllocateMemory(LogicalDevice, &MemoryAI, VkAllocators, &VboDeviceMemory[VboAllocCount]), "vkAllocateMemory failed!");

	VK_MCHECK(vkBindBufferMemory(LogicalDevice, *buffer, VboDeviceMemory[VboAllocCount], AlignedSize), "vkBindBufferMemory failed!");

	void *data;
	VK_MCHECK(vkMapMemory(LogicalDevice, VboDeviceMemory[VboAllocCount], 0, AlignedSize, 0, &data),"vkMapMemory failed!");

	VboAllocCount++;
	return data;
}

void *ZMalloc(s32 Size, u8 Zoneid)
{
	s32 Extra;
	memblock_t *Start, *Rover, *Newblock, *Base;

//
// scan through the block list looking for the first free block
// of sufficient size
//
	Size += sizeof(memblock_t);	// account for size of block header
#ifdef TINYENGINE_DEBUG
	Size += sizeof(s32);		// space for memory trash tester
#endif
	Size = (Size + (Mainzone[Zoneid]->Align-1)) & -Mainzone[Zoneid]->Align;
	//alignment must be consistent through out the allocator.

	Base = Rover = Mainzone[Zoneid]->Rover;
	Start = Base->Prev;

	do
	{
		if (Rover == Start)	// scaned all the way around the list
			return NULL;
		if (Rover->Tag)
			Base = Rover = Rover->Next;
		else
			Rover = Rover->Next;
	}
	while (Base->Tag || Base->Size < Size);

//
// found a block big enough
//
	Extra = Base->Size - Size;
	if (Extra > MINFRAGMENT)
	{
		// there will be a free fragment after the allocated block
		Newblock = (memblock_t *) ((unsigned char *)Base + Size );
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

	Mainzone[Zoneid]->Rover = Base->Next;	// next allocation will start looking here
	
#ifdef TINYENGINE_DEBUG
	// marker for memory trash testing
	Base->Id = ZONEID;
	*(int *)((unsigned char *)Base + Base->Size - sizeof(s32)) = ZONEID;
#endif

	return (void *) ((unsigned char *)Base + sizeof(memblock_t));
}

void ZFree(void *Ptr, u8 Zoneid)
{
	memblock_t *Block, *Other;
	
	if (!Ptr)
	{
		return;
	}

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
	Block->Tag = 0;	// mark as free

	Other = Block->Prev;
	if (!Other->Tag)
	{
		// merge with previous free block
		Other->Size += Block->Size;
		Other->Next = Block->Next;
		Other->Next->Prev = Other;
		if (Block == Mainzone[Zoneid]->Rover)
			Mainzone[Zoneid]->Rover = Other;
		Block = Other;
	}

	Other = Block->Next;
	if (!Other->Tag)
	{
		// merge the next free block onto the end
		Block->Size += Other->Size;
		Block->Next = Other->Next;
		Block->Next->Prev = Block;
		if (Other == Mainzone[Zoneid]->Rover)
			Mainzone[Zoneid]->Rover = Block;
	}
}

void ZInitZone(void *Mem, u32 Size, u32 Align, u8 Zoneid)
{
	memblock_t *Block;

	memzone_t *Zone = (memzone_t*)Mem;
	Mainzone[Zoneid] = Zone;
	Zone->Align = Align;
// set the entire zone to one free block

	Zone->Blocklist.Next = Zone->Blocklist.Prev = Block =
	                           (memblock_t *)( (unsigned char *)Zone + sizeof(memzone_t) );
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


b32 InitVulkan(PFN_vkGetInstanceProcAddr *GetProcAddr, void(SurfaceCallback(VkSurfaceKHR*)), u32 ReqExCount, const char **RequiredExtensions)
{
	u32 i;

	if(!GetProcAddr || !SurfaceCallback || !RequiredExtensions || !ReqExCount)
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


	//define custom vulkan allocators
	//allocators = NULL;
	if(VkAllocators)
	{
		//allocators->pUserData = NULL;
		//allocators->pfnAllocation =
		//allocators->pfnReallocation =
		//allocators->pfnFree =
		//allocators->pfnInternalAllocation = NULL;
		//allocators->pfnInternalFree = NULL;
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
			int size = (sizeof(VkExtensionProperties)  *DeviceExtensionCount);
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
	ASSERT(SwchImageSize.width, "Please call SetSizeOfSwapchainImages in SurfaceCallback before attempting init.");

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

	const char *DeviceExtensions[] = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
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

	vkGetDeviceQueue(LogicalDevice, QueueIndex[0], 0, &VkQueues[0]); //Graphics queue.
	//End Vulkan Queue

	//Swapchain
	SwchImageCount = SurfaceCapabilities.maxImageCount + 1;
	SwchImageViews = (VkImageView*) malloc(sizeof(VkImageView) * SwchImageCount);

	VkImageUsageFlags TmpImageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT |  VK_IMAGE_USAGE_TRANSFER_DST_BIT;
	SwchImageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT |  VK_IMAGE_USAGE_TRANSFER_DST_BIT;
	SwchImageUsage &= SurfaceCapabilities.supportedUsageFlags;
	ASSERT(TmpImageUsage == SwchImageUsage, "Swapchain images do not support Color | Transfer Attachments");

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

	CreateSwapchainImageViews();

	//End Swapchain

	//RENDER RESOURCES
	VkSemaphoreCreateInfo SemaphoreCI;
	SemaphoreCI.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
	SemaphoreCI.pNext = NULL;
	SemaphoreCI.flags = 0;

	VK_CHECK(vkCreateSemaphore(LogicalDevice, &SemaphoreCI, VkAllocators, &VkSemaphores[0]));
	VK_CHECK(vkCreateSemaphore(LogicalDevice, &SemaphoreCI, VkAllocators, &VkSemaphores[1]));

	VkFenceCreateInfo FenceCI;
	FenceCI.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
	FenceCI.pNext = NULL;
	FenceCI.flags = VK_FENCE_CREATE_SIGNALED_BIT;

	VK_CHECK(vkCreateFence(LogicalDevice, &FenceCI, VkAllocators, &VkFences[0]));
	VK_CHECK(vkCreateFence(LogicalDevice, &FenceCI, VkAllocators, &VkFences[1]));


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


	//MEMORY
	Trace("Reached target: Memory Init");
	vkGetPhysicalDeviceMemoryProperties(GpuDevice, &DeviceMemoryProperties);

	VertexBuffers[0].Data = VboMalloc(20480, &VertexBuffers[0].Buffer);
	VertexBuffers[0].Offset = 0;
	//Note(Kyryl): vertex buffers require no alignment.
	ZInitZone(VertexBuffers[0].Data, 20480, 1, 0);
	//End MEMORY

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



	//End RENDER RESOURCES

	return true;

}

#endif