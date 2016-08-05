//
//  H2HContainerManager.h
//  H2H
//
//  Created by Sagar Kasture on 14/01/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "H2HContainer.h"
#import "AppConstants.h"

@interface H2HContainerManager : NSObject

/*! @brief  Defines the standard size of container object */
@property (nonatomic, assign) CGSize  standardSize;

/*! @brief  Defines scroll position where currently expanded item is set */
@property (nonatomic, assign) NSInteger  scrollPosition;

/*!
 * @discussion Shared instance of container class.
 * @param None
 * @return instanceType is object of type H2HContainer
 */
+(instancetype) sharedInstance;

/*!
 * @discussion Cleares locally mainained data of all containers.
 */
-(void) clearLocalData;

/*!
 * @discussion Remove all containers and reset to default state.
 */
-(void) resetContainers;

/*!
 * @discussion Reset container to original sizes.
 */
-(void) resetLayout;

/*!
 * @discussion Sets size for a particular container object.
 * @param newSize is size to be set
 * @param index is the index of the container object of which size needs to be changed.
 */
-(void) setSize:(CGSize)newSize forObjectAtIndex:(NSInteger)index;

/*!
 * @discussion This methods gets the list of container objects.
 * @return NSArray is an array of container object.
 */
-(NSArray*) getContainers;

/*!
 * @discussion This method gets the list of view controllers in manager.
 * @return NSArray is an array of view controller object.
 */
-(NSArray*) getViewControllers;

/*!
 * @discussion Expands the container by standard size not more than maxSize.
 * @param index is the index of container which needs to be expanded
 * @param maxSize is the maximum size to which a container can expand.
 */
-(void) expandContainerAtIndex:(NSInteger)index maxSize:(CGSize)maxSize;

/*!
 * @discussion Adds a container to manager with particular type and object value.
 * @param type is type of container to be added.
 * @param object is the object that container holds.
 */
-(void) addContainerWithType:(CONTAINER_TYPE)type andObject:(NSObject*)object;

/*!
 * @discussion Method to exchange container at from index with container at to index.
 * @param fromIndex is the index of container that needs to be exchanged.
 * @param toIndex is the index of container with which exchange needs to be done.
 */
-(void) exchangeContainerAtIndex:(NSInteger)fromIndex withObjectAtIndex:(NSInteger)toIndex;

/*!
 * @discussion Checks if the given container is full screen.
 * @param container which needs to be checked if full screen.
 * @return YES if container is full screen, false otherwise.
 */
-(CONTAINER_STATE) getContainerState:(H2HContainer*)container;

/**
 *  @discussion Check in available container array if there is any full screen container.
 *  @return H2HContainer object which is full screen, nil otherwise.
 */
-(H2HContainer*) getFullScreenContainer;

/*!
 * @discussion Returns container for specified index.
 * @param index is the index of container which needs to be returned.
 */
-(H2HContainer *)containerAtIndex:(NSInteger)index;

/*!
 * @discussion Returns view controller for specified index.
 * @param index is the index of container which needs to be returned.
 */
-(UIViewController *)viewControllerAtIndex:(NSInteger)index;

@end