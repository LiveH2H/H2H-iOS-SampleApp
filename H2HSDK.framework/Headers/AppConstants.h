//
//  AppConstants.h
//  H2H
//
//  Created by pratima ghadage on 15/01/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#ifndef APP_CONSTANTS_H
#define APP_CONSTANTS_H

// Predefined Values
#define DEBUG                           1

// AWS   : 52.34.122.85:8089 | 52.10.96.151:8089 | 52.10.96.151:8443
// SPRING: 172.24.8.200:8080 | 172.24.8.178:8080

extern NSString* const WS_BASE_URL;
extern NSString* const WS_CHAT_WRAPPER_BASE_URL;
extern NSInteger const VIDEO_PARTICIPANTS_MAX_COUNT;

#define WEBRTC_CONNECTION_RETRY_DELAY   1
#define WEBRTC_CONNECTION_RETRY_COUNT   3

#define MENU_OPTIONS_COUNT              2
#define ADD_TILE_TYPES_COUNT            8

#define ORIGIN                          @"H2H"

// Button Index
#pragma mark -
#pragma mark Button Index

#define INDEX_CHECK_BUTTON              0
#define INDEX_MICROPHONE_BUTTON         1
#define INDEX_VIDEO_BUTTON              2
#define INDEX_WHITEBOARD_BUTTON         3

// Storyboard ID
#pragma mark -
#pragma mark Storyboard ID

#define STORYBOARD                      @"Main"
#define STID_MENU_OPTIONS_VIEW          @"STID_MENU_OPTIONS_VIEW"
#define STID_TRANSLATOR_LIST_TVC        @"STID_TRANSLATOR_LIST_TVC"
#define STID_ADD_NEW_TILE_OPTIONS       @"STID_ADD_NEW_TILE_OPTIONS"
#define STID_MANAGE_CHANGE_PARTICIPANT  @"STID_MANAGE_CHANGE_PARTICIPANT"
#define STID_VIDEO_CONFERENCE           @"STID_VIDEO_CONFERENCE"
#define STID_GROUP_CHAT                 @"STID_GROUP_CHAT"
#define STID_NEW_CHAT                   @"STID_NEW_CHAT"
#define STID_NETWORK_LOST               @"STID_NETWORK_LOST"

// Storyboard ID Cell Identifier
#pragma mark -
#pragma mark Cell Identifier

#define STID_MENU_OPTION_BASIC_CELL     @"STID_MENU_OPTION_BASIC_CELL"
#define STID_MENU_OPTION_SWITCH_CELL    @"STID_MENU_OPTION_SWITCH_CELL"
#define STID_ADD_TILE_TYPE_CELL         @"STID_ADD_TILE_TYPE_CELL"
#define STID_PARTICIPANT_TABLE_CELL     @"STID_PARTICIPANT_TABLE_CELL"
#define STID_CHAT_POPUP_TABLE_CELL      @"STID_CHAT_POPUP_TABLE_CELL"
#define STID_IN_CHAT_CELL               @"InChatMessageCell"
#define STID_OUT_CHAT_CELL              @"OutChatMessageCell"
#define STID_PRESENCE_CELL              @"presenceCell"
#define STID_TRANSLATOR_LIST_CELL       @"STID_TRANSLATOR_LIST_CELL"

#define KEY_IS_RECORD_ENABLED           @"KEY_IS_RECORD_ENABLED"
#define KEY_IS_SPEECH_TO_TEXT_ENABLED   @"KEY_IS_SPEECH_TO_TEXT_ENABLED"

// Segues
#pragma mark -
#pragma mark Segues

#define SEQUE_ADD_TILE                  @"SEQUE_ADD_TILE"
#define ST_SEGUE_JOIN_MEETING           @"ST_JOIN_MEETING_SEGUE"
#define ST_SEGUE_CHAT_LIST              @"ST_SEGUE_CHAT_LIST"

// Alert view tag
#pragma mark -
#pragma mark Alert View Tags

#define DISCONNECT_CONFRIMATION_ALERT   1001

// Web Services Parsing Keys
#pragma mark -
#pragma mark Launch Parameters Web Service Keys

#define key_API_version                                     @"h2h_api_version"
#define key_return                                          @"h2h_return"
#define key_meeting                                         @"h2h_meeting"
#define key_meeting_actual_end_time                         @"meeting_actual_end_time"
#define key_meeting_actual_start_time                       @"meeting_actual_start_time"
#define key_meeting_attendee_count                          @"meeting_attendee_count"
#define key_meeting_description                             @"meeting_description"
#define key_meeting_id                                      @"meeting_id"
#define key_meeting_location                                @"meeting_location"
#define key_meeting_recording                               @"meeting_recording"
#define key_meeting_scheduled_end_time                      @"meeting_scheduled_end_time"
#define key_meeting_scheduled_start_time                    @"meeting_scheduled_start_time"
#define key_meeting_status                                  @"meeting_status"
#define key_meeting_subject                                 @"meeting_subject"
#define key_meeting_type                                    @"meeting_type"
#define key_meeting_whiteboards                             @"meeting_whiteboards"
#define key_meeting_whiteboard_blank                        @"whiteboard_blank"
#define key_meeting_whiteboard_desc                         @"whiteboard_desc"
#define key_meeting_whiteboard_id                           @"whiteboard_id"
#define key_meeting_whiteboard_finished                     @""
#define key_meeting_whiteboard_pages                        @"whiteboard_pages"
#define key_meeting_whiteboard_presentation                 @"whiteboard_presentation"
#define key_meeting_whiteboard_status                       @"whiteboard_status"
#define key_meeting_origin                                  @"origin"
#define key_meeting_origin_meeeting_id                      @"origin_meeting_id"
#define key_h2h_meeting_participant                         @"h2h_meeting_participant"
#define key_h2h_meeting_participant_id                      @"meeting_participant_id"
#define key_h2h_meeting_participant_join_time               @"meeting_participant_join_time"
#define key_h2h_meeting_participant_leave_reason            @"meeting_participant_leave_reason"
#define key_h2h_meeting_participant_leave_time              @"meeting_participant_leave_time"
#define key_h2h_meeting_participant_participation_minutes   @"meeting_participant_participation_minutes"
#define key_h2h_meeting_participant_role                    @"meeting_participant_role"
#define key_h2h_meeting_participant_status                  @"meeting_participant_status"
#define key_h2h_meeting_participant_token                   @"meeting_participant_token"
#define key_h2h_meeting_participant_translator              @"meeting_translator"
#define key_user                                            @"h2h_user"
#define key_user_avatar                                     @"avatar"
#define key_user_email_address                              @"email_address"
#define key_user_first_name                                 @"first_name"
#define key_user_display_locale_code                        @"h2h_display_locale_code"
#define key_user_last_name                                  @"last_name"
#define key_user_login_email                                @"login_email"
#define key_user_origin                                     @"origin"
#define key_user_user_display_name                          @"user_display_name"
#define key_user_user_id                                    @"user_id"
#define key_origin_user_id                                  @"origin_user_id"
#define key_meeting_whiteboard_page_id                      @"whiteboard_page_id"
#define key_meeting_whiteboard_page_image                   @"whiteboard_page_image"
#define key_meeting_whiteboard_page_number                  @"whiteboard_page_number"
#define key_meeting_whiteboard_page_status                  @"whiteboard_page_status"
#define key_h2h_attendee                                    @"h2h_attendee"
#define key_h2h_attendee_display_name                       @"attendee_display_name"
#define key_h2h_attendee_id                                 @"attendee_id"
#define key_h2h_attendee_join_time                          @"attendee_join_time"
#define key_h2h_attendee_leave_reason                       @"attendee_leave_reason"
#define key_h2h_attendee_leave_time                         @"attendee_leave_time"
#define key_h2h_attendee_minutes                            @"attendee_minutes"
#define key_h2h_attendee_roles                              @"attendee_roles"
#define key_h2h_attendee_roles_actions                      @"actions"
#define key_h2h_attendee_roles_role_name                    @"role_name"
#define key_h2h_attendee_status                             @"attendee_status"
#define key_h2h_attendee_token                              @"attendee_token"
#define key_h2h_attendee_translator                         @"attendee_translator"
#define key_h2h_attendee_server_config                      @"server_config"
#define key_h2h_attendee_server_config_countries            @"countries"
#define key_h2h_attendee_server_config_stun_servers         @"stun_servers"
#define key_h2h_attendee_server_config_turn_servers         @"turn_servers"
#define key_h2h_attendee_server_urls                        @"urls"
#define key_h2h_attendee_server_credential                  @"credential"
#define key_h2h_attendee_server_username                    @"username"

#define value_action_turn_audio_on                          @"TURN_AUDIO_ON"
#define value_action_turn_audio_off                         @"TURN_AUDIO_OFF"
#define value_action_turn_video_on                          @"TURN_VIDEO_ON"
#define value_action_turn_video_off                         @"TURN_VIDEO_OFF"
#define value_action_turn_chat_on                           @"TURN_CHAT_ON"
#define value_action_turn_chat_off                          @"TURN_CHAT_OFF"
#define value_action_create_whiteboard                      @"CREATE_WHITEBOARD"
#define value_action_update_whiteboard                      @"UPDATE_WHITEBOARD"
#define value_action_grant_update_whiteboard_priviledge     @"GRANT_UPDATE_WB_PRIV"
#define value_action_turn_recording_on                      @"TURN_RECORDING_ON"
#define value_action_turn_recording_off                     @"TURN_RECORDING_OFF"
#define value_action_turn_transcript_on                     @"TURN_TRANSCRIPT_ON"
#define value_action_turn_transcript_off                    @"TURN_TRANSCRIPT_OFF"
#define value_h2h_host                                      @"H2H_HOST"
#define value_host                                          @"HOST"
#define value_h2h_attendee                                  @"H2H_ATTENDEE"
#define value_h                                             @"H"
#define value_p                                             @"P"
#define value_audio                                         @"audio"
#define value_video                                         @"video"
#define value_group                                         @"GROUP"
#define value_webinar                                       @"WEBINAR"

#pragma mark -
#pragma mark Initialize Chat Web Service Keys

#define key_chat_server_domain                              @"chatServerDomain"
#define key_chat_server_url                                 @"chatServerUrl"

// Notifications
#pragma mark -
#pragma mark Notifications

#define notification_category                       @"H2H_ACTION"
#define notification_new_chat_message_reply         @"H2H_notification_new_chat_messge_reply"
#define notification_local_video_enabled            @"H2H_notification_local_video_enabled"
#define notification_local_video_disabled           @"H2H_notification_local_video_disabled"
#define notification_local_audio_enabled            @"H2H_notification_local_audio_enabled"
#define notification_local_audio_disabled           @"H2H_notification_local_audio_disabled"
#define notification_network_reachablity_changed    @"H2H_notification_network_reachability_changed"

// Join Details
#define join_details_device_type         @"device_type"
#define join_details_device_os           @"device_os"
#define join_details_device_os_version   @"device_os_version"
#define join_details_network_type        @"network_type"
#define join_details_device_details      @"device_details"
#define join_details_model               @"model"
#define join_details_processor           @"processor"
#define join_details_memory              @"memory"
#define join_details_details             @"details"
#define join_details_device_vendor       @"device_vendor"
#define join_details_latitude            @"latitude"
#define join_details_longitude           @"longitude"
#define join_details_elevation           @"elevation"
#define join_details_device_id           @"device_id"
#define join_details_client_version      @"client_version"
#define join_details_build_number        @"build_number"

// Enumerations
#pragma mark - 
#pragma mark Enums
typedef NS_ENUM(NSUInteger, CONFERENCE_VIEW_TYPE)
{
    CONFERENCE_VIEW_TYPE_GALLERY,
    CONFERENCE_VIEW_TYPE_PRESENTER
};

typedef NS_ENUM(NSUInteger, CONTAINER_STATE)
{
    CONTAINER_STATE_NONE,
    CONTAINER_STATE_ORIGINAL,
    CONTAINER_STATE_FULL
};

typedef NS_ENUM(NSUInteger, CHILD_ACTIVITY_TYPE)
{
    CHILD_ACTIVITY_TYPE_EXPAND
};

typedef NS_ENUM(NSUInteger, COLLECTION_ACTIVITY_TYPE)
{
    COLLECTION_ACTIVITY_TYPE_VIDEO,
    COLLECTION_ACTIVITY_TYPE_AUDIO
};

#endif