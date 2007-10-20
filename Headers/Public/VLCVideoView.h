/*****************************************************************************
 * VLCVideoView.h: VLC.framework VLCVideoView header
 *****************************************************************************
 * Copyright (C) 2007 Pierre d'Herbemont
 * Copyright (C) 2007 the VideoLAN team
 * $Id$
 *
 * Authors: Pierre d'Herbemont <pdherbemont # videolan.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#import <Cocoa/Cocoa.h>

/* Notifications */
extern NSString *VLCVideoViewEnteredFullScreen;
extern NSString *VLCVideoViewLeftFullScreen;

@protocol VLCVideoViewDelegate
// Notifications defined in VLCVideoView.h
- (void)videoEnteredFullscreen:(NSNotification *)aNotification;
- (void)videoLeftFullscreen:(NSNotification *)aNotification;
@end

@protocol VLCOpenGLVoutEmbedding
- (void)addVoutSubview:(NSView *)view;
- (void)removeVoutSubview:(NSView *)view;

- (void)enterFullscreen;
- (void)leaveFullscreen;

- (BOOL)stretchesVideo;

//- (void)setOnTop: (BOOL)ontop; /* Do we really want that in protocol? */
@end

@interface VLCVideoView : NSView <VLCOpenGLVoutEmbedding>
{
    id delegate;
    NSColor *backColor;
    BOOL stretchesVideo;
    
    // TODO: Allow for view to report transparency to do some cool effects
    // with the video?
}

- (void)setDelegate:(id)value;
- (id)delegate;

- (void)setBackColor:(NSColor *)value;
- (NSColor *)backColor;

- (void)setStretchesVideo:(BOOL)value;
- (BOOL)stretchesVideo;

- (void)addVoutSubview:(NSView *)aView;
- (void)removeVoutSubview:(NSView *)aView;

- (void)enterFullscreen;
- (void)leaveFullscreen;

//- (void)setOnTop: (BOOL)ontop; /* Do we really want that in protocol? */

// The media controls that were here previously should be moved elsewhere.  This
// View is just that, a view not a controller. -- Moved to VLCMediaPlayer
@end
