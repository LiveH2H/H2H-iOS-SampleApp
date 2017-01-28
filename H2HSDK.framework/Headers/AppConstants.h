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

#define WEBRTC_CONNECTION_RETRY_DELAY   1
#define WEBRTC_CONNECTION_RETRY_COUNT   3

#define MENU_OPTIONS_COUNT              2
#define ADD_TILE_TYPES_COUNT            8

#define  MAX_ALLOWED_IPHONE_VIDEO_COUNT 6
#define  MAX_ALLOWED_IPAD_VIDEO_COUNT   6

#define MEDIA_CONSTRAINT_MIN_WIDTH_GROUP        @"352"
#define MEDIA_CONSTRAINT_MIN_HEIGHT_GROUP       @"288"
#define MEDIA_CONSTRAINT_MIN_FRAME_RATE_GROUP   @"5"
#define MEDIA_CONSTRAINT_MAX_WIDTH_GROUP        @"1920"
#define MEDIA_CONSTRAINT_MAX_HEIGHT_GROUP       @"1080"
#define MEDIA_CONSTRAINT_MAX_FRAME_RATE_GROUP   @"60"
#define MEDIA_CONSTRAINT_MIN_WIDTH_WEBINAR      @"640"
#define MEDIA_CONSTRAINT_MIN_HEIGHT_WEBINAR     @"480"
#define MEDIA_CONSTRAINT_MIN_FRAME_RATE_WEBINAR @"5"

// Button Index
#pragma mark -
#pragma mark Button Index

#define INDEX_CHECK_BUTTON              0
#define INDEX_MICROPHONE_BUTTON         1
#define INDEX_VIDEO_BUTTON              2
#define INDEX_WHITEBOARD_BUTTON         3
#define INDEX_USERNAME_LABEL            4

// Storyboard ID
#pragma mark -
#pragma mark Storyboard ID

#define STORYBOARD                      @"Main"
#define STID_BASE_VIEW_CONTROLLER       @"BaseViewController"
#define STID_MENU_OPTIONS_VIEW          @"STID_MENU_OPTIONS_VIEW"
#define STID_TRANSLATOR_LIST_TVC        @"STID_TRANSLATOR_LIST_TVC"
#define STID_ADD_NEW_TILE_OPTIONS       @"STID_ADD_NEW_TILE_OPTIONS"
#define STID_MANAGE_CHANGE_PARTICIPANT  @"STID_MANAGE_CHANGE_PARTICIPANT"
#define STID_VIDEO_CONFERENCE           @"STID_VIDEO_CONFERENCE"
#define STID_GROUP_CHAT                 @"STID_GROUP_CHAT"
#define STID_NEW_CHAT                   @"STID_NEW_CHAT"
#define STID_NETWORK_LOST               @"STID_NETWORK_LOST"
#define STID_REMINDER_TIMER_SETTING     @"STID_REMINDER_TIMER_SETTING"
#define STID_NEW_PARTICIPANT            @"H2HParticipantsViewController"
#define STID_CREATE_NEW_GROUP_CHAT      @"STID_CREATE_NEW_GROUP_CHAT"
#define STID_POLLING                    @"H2HPollViewController"

#define STID_MORE_OPTIONS               @"STID_MORE_OPTIONS"
#define STID_MORE_OPTIONS_NAVIGATION    @"STID_MORE_OPTIONS_NAVIGATION"
#define STID_LIVE_SUPPORT_ISSUE         @"STID_LIVE_SUPPORT_ISSUE"
#define STID_WHITEBOARD_IDENTIFIER      @"STID_WHITEBOARD_IDENTIFIER"
#define STID_NEW_CONTACT_ACCESS_DENIED  @"STID_NEW_CONTACT_ACCESS_DENIED"
#define STID_NETWORK_STATUS_INDICATOR   @"STID_NETWORK_STATUS_INDICATOR"
#define STID_MEETING_ID_DROP_DOWN @"H2HNewMeetingIDDropDownViewController"

#define STID_TEST_CONNECTION            @"STID_TEST_CONNECTION"

#define STORYBOARD_IPHONE_CHAT          @"H2H_New_UI_iPhone_Chat"
#define STORYBOARD_IPHONE_MORE_OPTIONS  @"H2H_New_UI_iPhone_MoreOptions"
#define STORYBOARD_IPHONE_LANDING       @"H2H_New_UI_iPhone_Landing"

#define STID_CHAT_VIEW_CONTROLLER       @"H2HChatViewController"
#define STID_OVERLAY_CHAT_VIEW_CONTROLLER       @"H2HOverlayChatViewController"
#define STID_PHONE_SWITCH_CHAT_VIEW_CONTROLLER       @"H2HPhoneSwitchChatViewController"
#define STID_PHONE_MORE_OPTIONS_CONTROLLER @"H2HNewMoreOptionsNavigationController"
#define STID_PHONE_VIDEOCONFERENCE_CONTROLLER   @"H2HVideoConferenceViewController"
#define STID_PHONE_WHITEBOARD_CONTROLLER @"H2HPhoneWhiteBoardBaseViewController"
#define STID_PHONE_TOOLBAR @"H2HPhoneToolbarViewController"

#define STID_FABRICJS_WHITEBOARD_VC @"H2HFabricJSWhiteboardViewController"
#define STID_FABRICJS_WHITEBOARD_CUSTOM_MENU_VC @"H2HCustomMenuViewController"
#define STID_DIALOG @"H2HDialogTableViewController"


// Storyboard ID Cell Identifier
#pragma mark -
#pragma mark Cell Identifier

#define STID_MENU_OPTION_BASIC_CELL     @"STID_MENU_OPTION_BASIC_CELL"
#define STID_MENU_OPTION_SWITCH_CELL    @"STID_MENU_OPTION_SWITCH_CELL"
#define STID_ADD_TILE_TYPE_CELL         @"STID_ADD_TILE_TYPE_CELL"
#define STID_PARTICIPANT_TABLE_CELL     @"STID_PARTICIPANT_TABLE_CELL"
#define STID_INVITEE_TABLE_CELL         @"STID_INVITEE_TABLE_CELL"
#define STID_CHAT_POPUP_TABLE_CELL      @"STID_CHAT_POPUP_TABLE_CELL"
#define STID_IN_CHAT_CELL               @"InChatMessageCell"
#define STID_OUT_CHAT_CELL              @"OutChatMessageCell"
#define STID_PRESENCE_CELL              @"presenceCell"
#define STID_OPAQUEU_CELL @"opaqueCell"
#define STID_MESSAGE_FROM_CELL @"MessagesFromCell"

#define STID_IN_CHAT_CELL_FOR_TRANSPARENT               @"InChatMessageCellForTransparent"
#define STID_OUT_CHAT_CELL_FOR_TRANSPARENT              @"OutChatMessageCellForTransparent"
#define STID_PRESENCE_CELL_FOR_TRANSPARENT              @"presenceCellForTransparent"

#define STID_IN_CHAT_CELL_FOR_OPAQUE               @"InChatMessageCellForOpaque"
#define STID_OUT_CHAT_CELL_FOR_OPAQUE              @"OutChatMessageCellForOpaque"
#define STID_PRESENCE_CELL_FOR_OPAQUE              @"presenceCellForOpaque"

#define STID_TRANSLATOR_LIST_CELL       @"STID_TRANSLATOR_LIST_CELL"
#define STID_SWITCH_CHAT_CELL           @"Switch_Chat_Cell"

#define  STID_MORE_OPTIONS_TABLE_CELL             @"STID_MORE_OPTIONS_TABLE_CELL"
#define  STID_LIVE_SUPPORT_TABLE_CELL             @"STID_LIVE_SUPPORT_TABLE_CELL"
#define  STID_PARTICIPANT_SETTING_TABLE_CELL      @"STID_PARTICIPANT_SETTING_TABLE_CELL"
#define  STID_MORE_OPTIONS_TABLE_CELL_STARTTIMER  @"STID_MORE_OPTIONS_TABLE_CELL_STARTTIMER"
#define  STID_REMINDER_TIMER_SETTING_CELL         @"STID_REMINDER_TIMER_SETTING_CELL"
#define  STID_WAITING_FOR_NETWORK_STATUS_CELL     @"STID_WAITING_FOR_NETWORK_STATUS_CELL"
#define  STID_NETWORK_STATUS_CELL                 @"STID_NETWORK_STATUS_CELL"

#define STID_MEETING_ID_DROPDOWN_DIAL_NUMB_CELL     @"STID_MEETING_ID_DROPDOWN_DIAL_NUMB_CELL"
#define STID_MEETING_ID_DROPDOWN_RECORD_CELL        @"STID_MEETING_ID_DROPDOWN_RECORD_CELL"
#define STID_MEETING_ID_DROPDOWN_MEETING_LINK_CELL  @"STID_MEETING_ID_DROPDOWN_MEETING_LINK_CELL"

#define STID_LIVE_SUPPORT_CELL          @"STID_LIVE_SUPPORT_CELL"

//Dialog Cell
#define STID_HEADER_TITLE_CELL @"STID_HEADER_TITLE_CELL"
#define STID_OPTION_1_CELL @"STID_OPTION_1_CELL"
#define STID_OPTION_2_CELL @"STID_OPTION_2_CELL"
#define STID_ACTION_CELL @"STID_ACTION_CELL"



#define KEY_IS_CHAT_OVERLAY_ENABLED           @"KEY_IS_CHAT_OVERLAY_ENABLED"
#define KEY_IS_RECORD_ENABLED           @"KEY_IS_RECORD_ENABLED"
#define KEY_IS_SPEECH_TO_TEXT_ENABLED   @"KEY_IS_SPEECH_TO_TEXT_ENABLED"
#define KEY_THEME_COLOR           @"KEY_THEME_COLOR"

// Segues
#pragma mark -
#pragma mark Segues

#define SEQUE_ADD_TILE                  @"SEQUE_ADD_TILE"
#define ST_SEGUE_JOIN_MEETING           @"ST_JOIN_MEETING_SEGUE"
#define ST_SEGUE_CHAT_LIST              @"ST_SEGUE_CHAT_LIST"

//NEW UI SEQUE
#define SEQUE_LIVE_SUPPORT              @"SEQUE_LIVE_SUPPORT"
#define SEGUE_LIVE_SUPPORT_LANGUAGE     @"SEGUE_LIVE_SUPPORT_LANGUAGE"
#define SEQUE_PARTICIPANT_SETTING       @"SEQUE_PARTICIPANT_SETTING"
#define STID_DEVICE_SETTING_TABLE_CELL  @"STID_DEVICE_SETTING_TABLE_CELL"
#define SEQUE_DEVICE_SETTING            @"SEQUE_DEVICE_SETTING"
#define STID_THEME_COLOR_CELL           @"STID_THEME_COLOR_CELL"
#define STID_THEME_COLOR_DEFAULT_CELL   @"STID_THEME_COLOR_DEFAULT_CELL"
#define SEQUE_THEME_COLOR               @"SEQUE_THEME_COLOR"


// Alert view tag
#pragma mark -
#pragma mark Alert View Tags

#define DISCONNECT_CONFRIMATION_ALERT   1001

// Web Services Parsing Keys
#pragma mark -
#pragma mark Launch Parameters Web Service Keys

#define vRequestLeaveReasonI                                (@"I")
#define vRequestLeaveReasonU                                (@"U")
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
#define key_meeting_invitees                                @"meeting_invitees"
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
#define key_user_email                                      @"email"
#define key_is_microphone_available                         @"isMicrophoneAvailable"
#define key_is_camera_available                             @"isCameraAvailable"
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
#define key_h2h_attendee_translator_language                @"translator_language"
#define key_h2h_attendee_translator_language_code           @"translator_language_code"
#define key_h2h_attendee_server_config                      @"server_config"
#define key_h2h_attendee_server_config_countries            @"countries"
#define key_h2h_attendee_server_config_wowza_url            @"wowza_url"
#define key_h2h_attendee_server_config_kms_turnurl          @"kms_turnurl"
#define key_h2h_attendee_server_config_relay_only           @"relay_only"
#define key_h2h_attendee_server_config_stun_servers         @"stun_servers"
#define key_h2h_attendee_server_config_turn_servers         @"turn_servers"
#define key_h2h_attendee_server_urls                        @"urls"
#define key_h2h_attendee_server_credential                  @"credential"
#define key_h2h_attendee_server_username                    @"username"
#define key_h2h_attendee_join_details                       @"attendee_join_details"
#define key_h2h_attendee_join_details_id                    @"join_details_id"
#define key_h2h_statusCode                                  @"statusCode"
#define key_h2h_message                                     @"message"

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
#define value_s                                             @"S"
#define value_audio                                         @"audio"
#define value_video                                         @"video"
#define value_group                                         @"GROUP"
#define value_webinar                                       @"WEBINAR"
#define value_is_audio_sticky                               @"isAudioSticky"
#define value_is_video_sticky                               @"isVideoSticky"

#pragma mark - Customisation Parameters
#define key_initial_settings                                @"initialSettings"
#define key_meeting_custom                                  @"meeting_custom"
#define key_meeting_enabled_features                        @"enabledFeatures"
#define key_enable_audio_control                            @"enableAttendeeAudioOnJoin"
#define key_enable_video_control                            @"enableAttendeeVideoOnJoin"
#define value_whiteboard                                    @"whiteboard"
#define value_chat                                          @"chat"
#define value_live_translator                               @"liveTranslator"
#define value_live_transcript                               @"liveTranscript"
#define value_raise_hand                                    @"raiseHand"
#define value_live_support                                  @"liveSupport"
#define value_poll                                          @"poll"
#define value_lock_UI                                       @"lockUI"
#define value_recording                                     @"recording"
#define value_invite_participant                            @"inviteParticipant"

#pragma mark - Meeting Type
#define MEETINGTYPE_STRING_GROUP        @"GROUP"
#define MEETINGTYPE_STRING_WEBINAR      @"WEBINAR"
#define MEETINGTYPE_STRING_BROADCAST    @"BROADCAST"

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
#define notification_live_chat_support_notification @"H2H_notification_live_chat_support_notification"
#define notification_deskpro_live_chat_support_notification @"H2H_notification_deskpro_live_chat_support_notification"
#define notification_iphone_video_fullscreen        @"H2H_notification_iphone_video_fullscreen"
#define notification_iphone_video_normal            @"H2H_notification_iphone_video_normal"
#define notification_iphone_participant_enabled     @"H2H_notification_participant_enabled"
#define notification_theme_changed                  @"H2H_notification_theme_changed"
#define notification_iphone_raise_hand_button_hidden    @"H2H_notification_iphone_raise_hand_button_hidden"
#define notification_live_support_issue_sended      @"H2H_notification_live_support_issue_sended"
#define notification_is_deskpro_chat_on_value_updated    @"H2H_notification_is_deskpro_chat_on_value_updated"
#define notification_hide_show_chat_progress_view        @"H2H_notification_hide_show_chat_progress_view"

#define notification_chat_permissions_updated       @"H2H_notification_chat_permissions_updated"
#define notification_raise_hand_permissions_received @"H2H_notification_raise_hand_permissions_received"

#define notification_live_support_dismiss      @"H2H_notification_live_support_dismiss"
#define notification_more_options_dismiss      @"H2H_notification_more_options_dismiss"
#define notification_push_live_chat      @"H2H_notification_push_live_chat"
#define notification_end_meeting                    @"H2H_notification_end_meeting"
#define notification_show_host_unavailable               @"H2H_notification_show_host_unvailable"


//More Options
#define notification_showLiveSupport                @"H2H_notification_showLiveSupport"
#define notification_submit_support_request         @"notification_submit_support_request"
#define notification_chat_overlay_setting_changed         @"notification_chat_overlay_setting_changed"

#define notification_change_tab_to_whiteboard         @"notification_change_tab_to_whiteboard"


//raise hand 
#define  notification_sort_participants_for_hand_raise @"H2H_notification_sort_participants_for_hand_raise"

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
#define join_details_device_temp_id      @"device_temp_id"
#define join_details_client_version      @"client_version"
#define join_details_build_number        @"build_number"

// Support Request
#define support_request_key_reason              @"reason"
#define support_request_key_comments            @"comments"
#define support_request_key_contact             @"contactBy"
#define support_request_key_contact_phone       @"Phone"
#define support_request_key_contact_wechat      @"weChat"
#define support_request_key_origin_meeting_id   @"origin_meeting_id"
#define support_request_key_meeting_id          @"meeting_id"
#define support_request_key_attendee_id         @"attendee_id"
#define support_request_key_origin              @"origin"
#define support_request_key_client_version      @"client_version"

//languages
#define LANGUAGE_CODE_ENGLISH_US @"ENGLISH_US"
#define LANGUAGE_CODE_ENGLISH_INDIA @"ENGLISH_IND"
#define LANGUAGE_CODE_FRENCH @"FRENCH"
#define LANGUAGE_CODE_GERMAN @"GERMAN"
#define LANGUAGE_CODE_CHINEESE @"CATONESE"
#define LANGUAGE_CODE_SPANISH @"SPANISH"
#define LANGUAGE_CODE_HINDI @"HINDI"

// User settings
#define kLiveSupportLanguageKey @"kLiveSupportLanguageKey"
#define kEnglishLanguageKey @"english"
#define kChineseLanguageKey @"chinese"
#define kIsChatOverlayEnabledKey @"kIsChatOverlayEnabledKey"
#define kIsLiveTranscriptEnabledKey @"kIsLiveTranscriptEnabledKey"
#define kIsAutomaticallyHideToolbarKey @"kIsAutomaticallyHideToolbarKey"
#define notification_user_setting_changed @"notification_user_setting_changed"
#define notification_language_changed @"notification_language_changed"


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
    CONTAINER_STATE_FULL,
    //BEGIN - Changes for adding content view
    CONTAINER_STATE_FULL_FROM_TOOBAR
    
    //END - Changes for adding content view
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

typedef NS_OPTIONS(NSUInteger, ChatMode) {
    ChatModeOpaque = 0,

    ChatModeTransparent = 1,
};

typedef NS_OPTIONS(NSUInteger, H2HNewChatViewMode) {
    H2HNewChatViewModeTransparent = 0,
    H2HNewChatViewModeOpaque = 1 << 0,
    H2HNewChatViewModeGrid = 1 << 2
};

typedef NS_OPTIONS(NSUInteger, ChatModeForIphone) {
    ChatModeDefaultIphone = 0,
    ChatModeOpaqueIphone = 1,
    ChatModeTransparentIphone = 2,
};

typedef NS_OPTIONS(NSUInteger, TranscriptLanguage) {
    TranscriptLanguageEnglishUS = 0,
    TranscriptLanguageEnglishIndia,
    TranscriptLanguageFrench,
    TranscriptLanguageGerman,
    TranscriptLanguageHindi,
    TranscriptLanguageChinese,
    TranscriptLanguageSpanish
};

typedef NS_OPTIONS(NSUInteger, EnumThemeColor)
{
    COLOR_BLACK=0,
    COLOR_RED,
    COLOR_ORANGE,
    COLOR_YELLOW,
    COLOR_GREEN,
    COLOR_LIGHT_BLUE,
    COLOR_BLUE,
    COLOR_PURPLE
};

typedef NS_OPTIONS(NSUInteger, InviteeState)
{
    UserStateAsInvitedNotJoined = 0,
    UserStateAsInvitedAndLeft
};

#endif
