/***********************************************************************************
 *  PIC Audio Player - A simple single chip solution to playing small audio files  *
 *  Created by mikemadealarms on April 16, 2016 at 5:45 PM                         *
 * ------------------------------------------------------------------------------- *
 *  Last modification by mikemadealarms on April 17, 2016 at 12:15 PM              *
 *  Last modification made was: Added a constant used for playing the recording    *
 ***********************************************************************************/

#include <xc.h>

#ifndef SOUND_H
#define SOUND_H

#define TOTAL_SAMPLES 6000  //The total number of samples within the audio recording

//Variable that stores the audio samples used by the PIC MCU for playback of the message
const char sound[] = {
  0x80, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7D, 0x7D, 0x7D, 0x7D,
  0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x80,
  0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x82, 0x82,
  0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x82, 0x82, 0x82, 0x83, 0x84,
  0x84, 0x84, 0x85, 0x85, 0x85, 0x85, 0x84, 0x81, 0x80, 0x7F, 0x7C, 0x7A,
  0x7A, 0x78, 0x76, 0x77, 0x77, 0x76, 0x77, 0x78, 0x78, 0x7A, 0x7C, 0x7D,
  0x7E, 0x81, 0x82, 0x82, 0x83, 0x84, 0x84, 0x84, 0x85, 0x84, 0x83, 0x83,
  0x81, 0x80, 0x7E, 0x78, 0x78, 0x79, 0x74, 0x73, 0x76, 0x73, 0x72, 0x76,
  0x74, 0x72, 0x76, 0x77, 0x77, 0x7B, 0x7E, 0x7D, 0x82, 0x86, 0x85, 0x86,
  0x88, 0x87, 0x87, 0x89, 0x88, 0x87, 0x88, 0x87, 0x87, 0x87, 0x86, 0x84,
  0x85, 0x86, 0x85, 0x86, 0x87, 0x8A, 0x8B, 0x8B, 0x83, 0x7F, 0x82, 0x7B,
  0x75, 0x78, 0x76, 0x6F, 0x74, 0x76, 0x70, 0x70, 0x74, 0x74, 0x74, 0x7B,
  0x7D, 0x7D, 0x82, 0x87, 0x85, 0x86, 0x89, 0x87, 0x87, 0x89, 0x88, 0x86,
  0x86, 0x85, 0x83, 0x83, 0x82, 0x80, 0x7F, 0x7F, 0x7E, 0x7C, 0x7C, 0x7A,
  0x73, 0x72, 0x74, 0x6F, 0x6D, 0x70, 0x6F, 0x6F, 0x75, 0x75, 0x73, 0x77,
  0x7B, 0x7A, 0x7E, 0x82, 0x81, 0x84, 0x89, 0x89, 0x88, 0x8A, 0x88, 0x87,
  0x88, 0x87, 0x85, 0x85, 0x84, 0x85, 0x86, 0x84, 0x83, 0x84, 0x85, 0x85,
  0x89, 0x8A, 0x8B, 0x8C, 0x92, 0x8A, 0x80, 0x87, 0x81, 0x75, 0x78, 0x7A,
  0x6F, 0x71, 0x78, 0x70, 0x6C, 0x73, 0x72, 0x70, 0x78, 0x7C, 0x7A, 0x7F,
  0x86, 0x84, 0x84, 0x89, 0x88, 0x85, 0x89, 0x8A, 0x85, 0x87, 0x88, 0x84,
  0x85, 0x86, 0x83, 0x81, 0x81, 0x7F, 0x7E, 0x7A, 0x74, 0x70, 0x70, 0x6F,
  0x6C, 0x6C, 0x6C, 0x6C, 0x71, 0x73, 0x72, 0x75, 0x77, 0x7A, 0x7F, 0x83,
  0x83, 0x87, 0x8B, 0x8C, 0x8D, 0x8E, 0x8B, 0x8A, 0x8B, 0x8A, 0x89, 0x88,
  0x86, 0x85, 0x87, 0x85, 0x83, 0x85, 0x85, 0x86, 0x89, 0x8B, 0x8D, 0x8E,
  0x92, 0x86, 0x7F, 0x88, 0x7E, 0x73, 0x78, 0x78, 0x6C, 0x6F, 0x78, 0x6D,
  0x6B, 0x73, 0x70, 0x70, 0x7A, 0x7E, 0x7B, 0x81, 0x88, 0x87, 0x88, 0x8C,
  0x89, 0x87, 0x8B, 0x8C, 0x87, 0x88, 0x89, 0x84, 0x85, 0x86, 0x84, 0x81,
  0x80, 0x7F, 0x7A, 0x71, 0x71, 0x73, 0x6B, 0x69, 0x6F, 0x6C, 0x6B, 0x73,
  0x73, 0x6F, 0x76, 0x7B, 0x7B, 0x82, 0x87, 0x85, 0x8A, 0x91, 0x8F, 0x8E,
  0x91, 0x8E, 0x8B, 0x8F, 0x8E, 0x88, 0x89, 0x89, 0x85, 0x86, 0x87, 0x84,
  0x83, 0x86, 0x87, 0x89, 0x8D, 0x8E, 0x8F, 0x91, 0x85, 0x80, 0x86, 0x7B,
  0x73, 0x76, 0x73, 0x6A, 0x70, 0x75, 0x6C, 0x6C, 0x72, 0x72, 0x73, 0x7C,
  0x80, 0x7D, 0x83, 0x89, 0x88, 0x8A, 0x8D, 0x8A, 0x88, 0x8C, 0x8C, 0x88,
  0x88, 0x87, 0x83, 0x85, 0x86, 0x84, 0x81, 0x81, 0x78, 0x70, 0x76, 0x74,
  0x6B, 0x6D, 0x6E, 0x69, 0x6E, 0x75, 0x71, 0x6F, 0x76, 0x79, 0x7C, 0x84,
  0x87, 0x84, 0x88, 0x8D, 0x8D, 0x8E, 0x8F, 0x8B, 0x8A, 0x8C, 0x8B, 0x89,
  0x88, 0x86, 0x85, 0x85, 0x86, 0x86, 0x87, 0x86, 0x87, 0x8C, 0x90, 0x91,
  0x93, 0x8E, 0x7B, 0x7F, 0x83, 0x75, 0x73, 0x75, 0x6E, 0x67, 0x6F, 0x75,
  0x6F, 0x6F, 0x73, 0x73, 0x73, 0x7C, 0x82, 0x80, 0x82, 0x87, 0x86, 0x86,
  0x8D, 0x8D, 0x87, 0x88, 0x8A, 0x86, 0x89, 0x8D, 0x89, 0x85, 0x83, 0x80,
  0x7C, 0x7A, 0x77, 0x6E, 0x67, 0x6C, 0x6E, 0x6E, 0x71, 0x71, 0x6D, 0x70,
  0x79, 0x79, 0x7B, 0x7F, 0x7D, 0x82, 0x85, 0x82, 0x86, 0x8A, 0x89, 0x8B,
  0x89, 0x87, 0x89, 0x86, 0x84, 0x8A, 0x88, 0x85, 0x88, 0x89, 0x89, 0x8C,
  0x90, 0x8D, 0x96, 0x9C, 0x94, 0x86, 0x6A, 0x6B, 0x6A, 0x67, 0x78, 0x75,
  0x6E, 0x6D, 0x70, 0x7A, 0x80, 0x82, 0x80, 0x7B, 0x79, 0x7D, 0x82, 0x83,
  0x7F, 0x79, 0x7A, 0x7B, 0x80, 0x8B, 0x86, 0x85, 0x89, 0x85, 0x89, 0x8F,
  0x87, 0x83, 0x80, 0x72, 0x6C, 0x69, 0x67, 0x6B, 0x71, 0x74, 0x77, 0x7C,
  0x7D, 0x7C, 0x79, 0x78, 0x79, 0x7B, 0x7F, 0x84, 0x88, 0x8C, 0x8F, 0x8D,
  0x8D, 0x8A, 0x89, 0x88, 0x84, 0x85, 0x87, 0x87, 0x87, 0x83, 0x88, 0x8B,
  0x8F, 0x97, 0x9C, 0xA3, 0xA3, 0x9B, 0x67, 0x3F, 0x51, 0x44, 0x5C, 0x8B,
  0x7F, 0x7E, 0x89, 0x8C, 0x96, 0xA0, 0x91, 0x74, 0x6B, 0x67, 0x69, 0x79,
  0x7D, 0x71, 0x74, 0x81, 0x8E, 0xA3, 0xA1, 0x91, 0x84, 0x74, 0x6F, 0x76,
  0x78, 0x6F, 0x70, 0x6D, 0x6A, 0x7F, 0x87, 0x75, 0x7B, 0x80, 0x79, 0x83,
  0x88, 0x77, 0x6E, 0x73, 0x75, 0x82, 0x8D, 0x88, 0x87, 0x88, 0x88, 0x8B,
  0x92, 0x8E, 0x86, 0x81, 0x7A, 0x7F, 0x87, 0x83, 0x86, 0x8C, 0x87, 0x9A,
  0xA5, 0xAB, 0xB8, 0xA6, 0x63, 0x2C, 0x34, 0x33, 0x5B, 0xA0, 0xA2, 0x98,
  0x96, 0x83, 0x83, 0x94, 0x87, 0x69, 0x60, 0x5B, 0x63, 0x8A, 0x9B, 0x90,
  0x87, 0x7B, 0x82, 0x95, 0x9D, 0x8E, 0x7B, 0x61, 0x55, 0x68, 0x78, 0x83,
  0x88, 0x80, 0x6C, 0x75, 0x79, 0x72, 0x7D, 0x7A, 0x6E, 0x71, 0x7A, 0x7A,
  0x88, 0x8D, 0x83, 0x8C, 0x8F, 0x83, 0x86, 0x88, 0x7D, 0x87, 0x8A, 0x88,
  0x8E, 0x8E, 0x88, 0x84, 0x8B, 0x87, 0x91, 0x96, 0xA2, 0xB2, 0xB2, 0x70,
  0x20, 0x2D, 0x1F, 0x4A, 0xB1, 0xB7, 0xB3, 0x9B, 0x78, 0x6F, 0x7D, 0x85,
  0x69, 0x67, 0x59, 0x5B, 0x87, 0x9A, 0x9D, 0x99, 0x89, 0x7B, 0x83, 0x8F,
  0x82, 0x82, 0x6C, 0x5A, 0x66, 0x75, 0x84, 0x84, 0x78, 0x5D, 0x62, 0x7E,
  0x7D, 0x8F, 0x86, 0x64, 0x63, 0x6D, 0x81, 0x98, 0xA1, 0x8E, 0x88, 0x85,
  0x80, 0x8B, 0x8D, 0x8B, 0x89, 0x8A, 0x91, 0x99, 0x9C, 0x96, 0x95, 0x91,
  0xA0, 0xAB, 0x9E, 0x5A, 0x16, 0x23, 0x27, 0x64, 0xBF, 0xC8, 0xB3, 0x8E,
  0x62, 0x54, 0x72, 0x87, 0x7C, 0x76, 0x66, 0x64, 0x84, 0xA4, 0xA2, 0x9A,
  0x83, 0x6D, 0x75, 0x86, 0x8A, 0x8A, 0x7A, 0x60, 0x5D, 0x64, 0x75, 0x80,
  0x8A, 0x80, 0x7C, 0x7C, 0x77, 0x71, 0x6B, 0x67, 0x6D, 0x7F, 0x91, 0x9E,
  0xA0, 0x90, 0x80, 0x7D, 0x7F, 0x8A, 0x96, 0x9B, 0x9B, 0x9E, 0x99, 0x9E,
  0xA2, 0xAB, 0x9D, 0x8E, 0x4A, 0x20, 0x31, 0x37, 0x7E, 0xAD, 0xC1, 0xA9,
  0x8F, 0x6D, 0x54, 0x71, 0x70, 0x75, 0x73, 0x6C, 0x76, 0x87, 0x9F, 0x98,
  0x96, 0x85, 0x77, 0x7D, 0x82, 0x84, 0x84, 0x77, 0x57, 0x65, 0x74, 0x7A,
  0x93, 0x95, 0x81, 0x77, 0x6F, 0x64, 0x65, 0x6A, 0x6E, 0x82, 0x90, 0x99,
  0xA2, 0x9E, 0x8C, 0x85, 0x80, 0x80, 0x8D, 0x98, 0xA3, 0xA6, 0xA1, 0x9F,
  0x97, 0x95, 0x67, 0x34, 0x43, 0x3F, 0x6D, 0xA8, 0xBD, 0xA9, 0x8D, 0x77,
  0x57, 0x71, 0x7B, 0x74, 0x70, 0x6A, 0x68, 0x7E, 0x9F, 0x9B, 0x92, 0x85,
  0x6C, 0x73, 0x82, 0x89, 0x80, 0x6A, 0x63, 0x5D, 0x6F, 0x82, 0x8B, 0x8E,
  0x85, 0x7D, 0x74, 0x73, 0x6E, 0x6D, 0x75, 0x80, 0x8B, 0x9C, 0xA3, 0x9F,
  0x94, 0x8E, 0x89, 0x8A, 0x8F, 0x96, 0x93, 0x93, 0x96, 0x90, 0x66, 0x4A,
  0x54, 0x51, 0x74, 0x9C, 0xA9, 0x99, 0x82, 0x6B, 0x5A, 0x69, 0x7A, 0x7F,
  0x85, 0x7F, 0x7B, 0x83, 0x8C, 0x8D, 0x88, 0x80, 0x76, 0x74, 0x7E, 0x84,
  0x76, 0x6D, 0x64, 0x62, 0x6F, 0x79, 0x84, 0x87, 0x7E, 0x78, 0x71, 0x74,
  0x74, 0x79, 0x7A, 0x82, 0x8D, 0x98, 0xA0, 0x98, 0x90, 0x8B, 0x8E, 0x94,
  0x9A, 0x9E, 0xA2, 0x93, 0x84, 0x4B, 0x3F, 0x49, 0x5E, 0x8E, 0xA5, 0xA6,
  0x88, 0x7B, 0x6A, 0x62, 0x72, 0x6F, 0x72, 0x7B, 0x7F, 0x88, 0x90, 0x98,
  0x85, 0x7E, 0x78, 0x7B, 0x7D, 0x8A, 0x7C, 0x66, 0x68, 0x5A, 0x6F, 0x7C,
  0x87, 0x86, 0x83, 0x7D, 0x74, 0x70, 0x6E, 0x6F, 0x75, 0x7E, 0x8D, 0x9A,
  0x9E, 0xA0, 0x96, 0x99, 0x94, 0x9A, 0x99, 0x96, 0x94, 0x8D, 0x6D, 0x43,
  0x57, 0x5E, 0x77, 0xA1, 0xAA, 0x97, 0x7A, 0x72, 0x5D, 0x60, 0x73, 0x71,
  0x78, 0x7D, 0x8B, 0x8B, 0x91, 0x8F, 0x7D, 0x7B, 0x7F, 0x7F, 0x80, 0x85,
  0x68, 0x68, 0x69, 0x6E, 0x83, 0x86, 0x86, 0x7D, 0x7A, 0x75, 0x73, 0x78,
  0x70, 0x75, 0x7F, 0x86, 0x91, 0x98, 0x98, 0x8E, 0x95, 0x95, 0x9C, 0x9A,
  0x9D, 0x91, 0x88, 0x71, 0x3D, 0x57, 0x68, 0x7F, 0xA0, 0xAA, 0x9C, 0x7B,
  0x7B, 0x6C, 0x69, 0x74, 0x6E, 0x70, 0x77, 0x8C, 0x8A, 0x8F, 0x8D, 0x7B,
  0x76, 0x7D, 0x86, 0x84, 0x88, 0x70, 0x6A, 0x6E, 0x69, 0x75, 0x7C, 0x83,
  0x81, 0x86, 0x85, 0x75, 0x75, 0x70, 0x72, 0x7D, 0x8C, 0x91, 0x95, 0x9B,
  0x91, 0x9B, 0x9C, 0x9A, 0x96, 0x98, 0x8F, 0x86, 0x6F, 0x44, 0x57, 0x67,
  0x7E, 0x99, 0xA4, 0x98, 0x7F, 0x83, 0x72, 0x6E, 0x70, 0x71, 0x71, 0x78,
  0x8D, 0x8B, 0x8F, 0x89, 0x7F, 0x7A, 0x80, 0x84, 0x7F, 0x79, 0x65, 0x6D,
  0x6C, 0x6C, 0x7B, 0x80, 0x81, 0x82, 0x89, 0x7B, 0x78, 0x79, 0x77, 0x7E,
  0x84, 0x8F, 0x92, 0x9A, 0x99, 0x98, 0x99, 0x98, 0x97, 0x91, 0x9A, 0x8C,
  0x7B, 0x55, 0x43, 0x5E, 0x69, 0x85, 0x9C, 0xA0, 0x8D, 0x87, 0x87, 0x6E,
  0x6B, 0x67, 0x69, 0x6E, 0x89, 0x95, 0x8F, 0x93, 0x87, 0x81, 0x80, 0x84,
  0x78, 0x76, 0x6F, 0x67, 0x71, 0x6D, 0x6C, 0x76, 0x84, 0x83, 0x88, 0x86,
  0x78, 0x77, 0x78, 0x78, 0x79, 0x80, 0x8B, 0x93, 0xA2, 0xA0, 0x9A, 0x9D,
  0x9C, 0x92, 0x94, 0x95, 0x82, 0x75, 0x50, 0x53, 0x67, 0x6F, 0x85, 0x8E,
  0x96, 0x89, 0x90, 0x86, 0x75, 0x6D, 0x67, 0x69, 0x70, 0x86, 0x87, 0x8C,
  0x88, 0x8A, 0x89, 0x89, 0x88, 0x77, 0x7A, 0x65, 0x68, 0x72, 0x69, 0x67,
  0x73, 0x7E, 0x7A, 0x86, 0x85, 0x81, 0x7B, 0x7E, 0x75, 0x74, 0x85, 0x85,
  0x90, 0x98, 0x9A, 0x99, 0x9F, 0x9E, 0x97, 0x9E, 0x9C, 0x88, 0x71, 0x4D,
  0x50, 0x64, 0x6E, 0x7F, 0x8E, 0x97, 0x8E, 0x92, 0x86, 0x77, 0x69, 0x67,
  0x67, 0x6D, 0x7D, 0x84, 0x87, 0x8A, 0x95, 0x88, 0x8A, 0x8A, 0x80, 0x76,
  0x79, 0x66, 0x60, 0x6B, 0x65, 0x76, 0x7D, 0x83, 0x83, 0x84, 0x82, 0x7A,
  0x76, 0x74, 0x73, 0x7A, 0x84, 0x89, 0x93, 0x9B, 0x9C, 0x9C, 0x9E, 0x99,
  0x93, 0x93, 0x98, 0x89, 0x7A, 0x51, 0x4E, 0x67, 0x66, 0x77, 0x8A, 0x93,
  0x8A, 0x9B, 0x93, 0x78, 0x70, 0x6F, 0x68, 0x6B, 0x7C, 0x7B, 0x80, 0x8A,
  0x93, 0x89, 0x8B, 0x8B, 0x83, 0x7F, 0x76, 0x7A, 0x5F, 0x59, 0x75, 0x66,
  0x66, 0x80, 0x83, 0x83, 0x87, 0x83, 0x73, 0x77, 0x78, 0x69, 0x7A, 0x85,
  0x80, 0x91, 0x9B, 0x99, 0x95, 0x9D, 0x98, 0x94, 0x9C, 0x95, 0x92, 0x91,
  0x75, 0x46, 0x5F, 0x6A, 0x62, 0x75, 0x86, 0x8D, 0x89, 0x95, 0x8A, 0x78,
  0x75, 0x79, 0x6A, 0x6C, 0x6D, 0x76, 0x7F, 0x86, 0x88, 0x88, 0x8F, 0x88,
  0x88, 0x82, 0x7E, 0x7A, 0x75, 0x5D, 0x6A, 0x77, 0x69, 0x73, 0x83, 0x80,
  0x76, 0x82, 0x7D, 0x74, 0x77, 0x74, 0x76, 0x80, 0x84, 0x87, 0x8D, 0x95,
  0x8F, 0x91, 0x98, 0x94, 0x97, 0x95, 0x90, 0x9D, 0x9C, 0x94, 0x69, 0x52,
  0x76, 0x61, 0x59, 0x6E, 0x82, 0x80, 0x84, 0x9C, 0x81, 0x7B, 0x87, 0x79,
  0x66, 0x68, 0x77, 0x73, 0x7A, 0x85, 0x7F, 0x8A, 0x96, 0x8D, 0x82, 0x87,
  0x8C, 0x7D, 0x74, 0x67, 0x6B, 0x73, 0x6D, 0x6F, 0x74, 0x84, 0x82, 0x7F,
  0x7B, 0x77, 0x79, 0x72, 0x72, 0x75, 0x7E, 0x86, 0x8C, 0x8D, 0x8D, 0x94,
  0x9C, 0x97, 0x95, 0x95, 0x98, 0x9E, 0x8E, 0x9D, 0x9A, 0x97, 0x64, 0x54,
  0x7E, 0x53, 0x56, 0x6E, 0x76, 0x75, 0x7A, 0x8E, 0x7E, 0x84, 0x95, 0x7A,
  0x77, 0x77, 0x7A, 0x73, 0x74, 0x7F, 0x78, 0x89, 0x8F, 0x8B, 0x8B, 0x91,
  0x90, 0x8A, 0x85, 0x82, 0x62, 0x6B, 0x7E, 0x57, 0x63, 0x7B, 0x77, 0x72,
  0x85, 0x84, 0x74, 0x8C, 0x81, 0x72, 0x85, 0x89, 0x7C, 0x88, 0x8F, 0x8E,
  0x8A, 0x95, 0x96, 0x8E, 0x90, 0x92, 0x98, 0x99, 0x8B, 0x95, 0x9F, 0x91,
  0x8F, 0x4D, 0x75, 0x76, 0x49, 0x5B, 0x6C, 0x78, 0x68, 0x83, 0x86, 0x91,
  0x8B, 0x93, 0x81, 0x7D, 0x8A, 0x6E, 0x76, 0x79, 0x7E, 0x79, 0x81, 0x89,
  0x86, 0x90, 0x87, 0x89, 0x8A, 0x89, 0x7E, 0x72, 0x68, 0x77, 0x6D, 0x53,
  0x73, 0x77, 0x6E, 0x77, 0x82, 0x7C, 0x87, 0x84, 0x84, 0x84, 0x84, 0x89,
  0x83, 0x89, 0x8B, 0x8B, 0x87, 0x89, 0x8B, 0x8F, 0x8A, 0x8A, 0x8F, 0x8F,
  0x88, 0x92, 0x8C, 0x9B, 0x97, 0xAC, 0x6E, 0x5D, 0x94, 0x5E, 0x42, 0x59,
  0x8C, 0x55, 0x69, 0x87, 0x85, 0x90, 0x8B, 0x91, 0x80, 0x94, 0x89, 0x72,
  0x82, 0x80, 0x78, 0x70, 0x76, 0x7E, 0x7B, 0x89, 0x80, 0x8B, 0x91, 0x92,
  0x86, 0x89, 0x8A, 0x7D, 0x61, 0x61, 0x77, 0x5C, 0x5F, 0x71, 0x80, 0x7C,
  0x82, 0x89, 0x86, 0x8C, 0x7F, 0x7A, 0x7C, 0x82, 0x7A, 0x7E, 0x86, 0x89,
  0x8E, 0x89, 0x8F, 0x8F, 0x92, 0x8A, 0x82, 0x94, 0x8A, 0x82, 0x8E, 0x8D,
  0x96, 0x8E, 0xAC, 0x73, 0x62, 0x8E, 0x63, 0x50, 0x57, 0x82, 0x55, 0x68,
  0x82, 0x75, 0x8D, 0x89, 0x8B, 0x7A, 0x99, 0x8D, 0x75, 0x85, 0x88, 0x82,
  0x70, 0x81, 0x7F, 0x7A, 0x83, 0x7D, 0x87, 0x8A, 0x8B, 0x7D, 0x84, 0x88,
  0x7E, 0x72, 0x5B, 0x77, 0x6E, 0x59, 0x65, 0x7B, 0x77, 0x6F, 0x85, 0x82,
  0x8E, 0x8B, 0x7F, 0x83, 0x91, 0x8B, 0x79, 0x8E, 0x8F, 0x87, 0x89, 0x89,
  0x86, 0x89, 0x8A, 0x7B, 0x85, 0x89, 0x82, 0x7C, 0x86, 0x8B, 0x80, 0x87,
  0x8C, 0x93, 0x95, 0x9C, 0x72, 0x76, 0x90, 0x6A, 0x58, 0x69, 0x7F, 0x5C,
  0x67, 0x79, 0x77, 0x83, 0x83, 0x87, 0x83, 0x98, 0x8F, 0x7E, 0x87, 0x88,
  0x82, 0x75, 0x7C, 0x77, 0x78, 0x78, 0x75, 0x79, 0x7A, 0x80, 0x73, 0x79,
  0x80, 0x78, 0x76, 0x7B, 0x7E, 0x77, 0x7B, 0x78, 0x78, 0x7C, 0x7C, 0x7B,
  0x80, 0x87, 0x83, 0x86, 0x88, 0x88, 0x89, 0x88, 0x84, 0x85, 0x89, 0x7F,
  0x80, 0x80, 0x7E, 0x7C, 0x7A, 0x7C, 0x7E, 0x80, 0x7B, 0x7F, 0x7F, 0x82,
  0x81, 0x83, 0x8A, 0x88, 0x8B, 0x8A, 0x94, 0x9A, 0x97, 0x87, 0x80, 0x8B,
  0x78, 0x6B, 0x6A, 0x71, 0x68, 0x66, 0x6D, 0x6C, 0x77, 0x79, 0x78, 0x78,
  0x87, 0x88, 0x7F, 0x8A, 0x8E, 0x88, 0x85, 0x88, 0x82, 0x7C, 0x7C, 0x79,
  0x77, 0x75, 0x74, 0x76, 0x7B, 0x79, 0x7C, 0x82, 0x84, 0x80, 0x81, 0x85,
  0x7F, 0x7E, 0x7C, 0x7C, 0x7A, 0x7F, 0x7F, 0x7C, 0x7E, 0x83, 0x81, 0x7B,
  0x82, 0x84, 0x84, 0x83, 0x86, 0x87, 0x86, 0x84, 0x81, 0x80, 0x7E, 0x7C,
  0x7C, 0x7A, 0x79, 0x7C, 0x80, 0x81, 0x7F, 0x85, 0x86, 0x86, 0x85, 0x88,
  0x88, 0x86, 0x8A, 0x8A, 0x8D, 0x8F, 0x92, 0x8E, 0x8A, 0x84, 0x80, 0x7C,
  0x75, 0x71, 0x6D, 0x6C, 0x6B, 0x6C, 0x6A, 0x6E, 0x72, 0x77, 0x77, 0x7B,
  0x81, 0x84, 0x87, 0x84, 0x87, 0x8A, 0x89, 0x85, 0x80, 0x83, 0x83, 0x7D,
  0x79, 0x7C, 0x80, 0x7E, 0x7D, 0x7C, 0x83, 0x81, 0x7C, 0x79, 0x7C, 0x80,
  0x78, 0x7A, 0x7A, 0x83, 0x82, 0x7D, 0x81, 0x83, 0x83, 0x7D, 0x7E, 0x7E,
  0x80, 0x7E, 0x7D, 0x81, 0x82, 0x84, 0x82, 0x85, 0x88, 0x86, 0x86, 0x83,
  0x83, 0x83, 0x81, 0x7D, 0x7D, 0x7F, 0x7E, 0x7A, 0x7A, 0x7E, 0x81, 0x7E,
  0x7F, 0x85, 0x86, 0x85, 0x83, 0x86, 0x86, 0x84, 0x84, 0x82, 0x83, 0x84,
  0x81, 0x81, 0x82, 0x83, 0x82, 0x84, 0x84, 0x83, 0x82, 0x81, 0x81, 0x7E,
  0x7F, 0x7D, 0x7C, 0x7B, 0x7C, 0x7B, 0x79, 0x7C, 0x7E, 0x7E, 0x7B, 0x7E,
  0x81, 0x7E, 0x7E, 0x7E, 0x7F, 0x81, 0x7F, 0x7E, 0x80, 0x84, 0x81, 0x7C,
  0x81, 0x81, 0x7E, 0x7D, 0x7F, 0x7F, 0x7D, 0x7F, 0x7D, 0x80, 0x81, 0x7F,
  0x7E, 0x80, 0x80, 0x7F, 0x80, 0x7C, 0x82, 0x81, 0x81, 0x81, 0x82, 0x86,
  0x81, 0x81, 0x82, 0x85, 0x80, 0x81, 0x80, 0x7E, 0x81, 0x7D, 0x7D, 0x7D,
  0x7F, 0x7E, 0x7F, 0x80, 0x7F, 0x7F, 0x82, 0x82, 0x80, 0x83, 0x83, 0x80,
  0x7F, 0x80, 0x7F, 0x7D, 0x7C, 0x7F, 0x7C, 0x7E, 0x81, 0x80, 0x7E, 0x80,
  0x82, 0x7E, 0x80, 0x7D, 0x7E, 0x80, 0x7E, 0x7E, 0x7E, 0x80, 0x80, 0x80,
  0x80, 0x83, 0x82, 0x82, 0x82, 0x80, 0x81, 0x80, 0x7E, 0x7D, 0x7E, 0x80,
  0x7C, 0x7E, 0x7F, 0x7B, 0x7C, 0x7D, 0x7D, 0x7F, 0x7F, 0x7F, 0x7F, 0x81,
  0x80, 0x7F, 0x82, 0x7F, 0x83, 0x7C, 0x80, 0x82, 0x80, 0x7E, 0x7E, 0x80,
  0x7E, 0x7F, 0x7D, 0x81, 0x7E, 0x7F, 0x7F, 0x7D, 0x7D, 0x7C, 0x7C, 0x7C,
  0x7C, 0x80, 0x7E, 0x7F, 0x81, 0x80, 0x81, 0x80, 0x81, 0x81, 0x82, 0x80,
  0x80, 0x81, 0x80, 0x82, 0x80, 0x82, 0x83, 0x7E, 0x80, 0x80, 0x80, 0x7B,
  0x7C, 0x7D, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x81, 0x80, 0x81, 0x84, 0x81,
  0x83, 0x80, 0x82, 0x80, 0x80, 0x82, 0x7F, 0x80, 0x80, 0x83, 0x7C, 0x81,
  0x80, 0x7D, 0x7E, 0x7D, 0x7F, 0x81, 0x7D, 0x7C, 0x80, 0x81, 0x7C, 0x7F,
  0x80, 0x7C, 0x7D, 0x7E, 0x80, 0x7D, 0x80, 0x7F, 0x7C, 0x81, 0x81, 0x83,
  0x80, 0x82, 0x80, 0x80, 0x82, 0x7C, 0x83, 0x7D, 0x7F, 0x7F, 0x7E, 0x7E,
  0x7F, 0x7D, 0x80, 0x7F, 0x7F, 0x7F, 0x7D, 0x81, 0x80, 0x80, 0x7F, 0x86,
  0x80, 0x82, 0x80, 0x81, 0x81, 0x7E, 0x80, 0x7F, 0x81, 0x81, 0x7F, 0x7F,
  0x83, 0x7F, 0x83, 0x7F, 0x81, 0x81, 0x80, 0x7F, 0x7E, 0x80, 0x7E, 0x7D,
  0x7F, 0x7C, 0x80, 0x80, 0x7F, 0x83, 0x7D, 0x82, 0x7D, 0x81, 0x7D, 0x81,
  0x80, 0x80, 0x82, 0x7B, 0x81, 0x7E, 0x80, 0x7C, 0x80, 0x7E, 0x80, 0x7D,
  0x7E, 0x80, 0x7E, 0x81, 0x7F, 0x80, 0x80, 0x80, 0x7D, 0x81, 0x7D, 0x7F,
  0x7F, 0x81, 0x81, 0x7E, 0x7F, 0x7E, 0x7F, 0x7E, 0x7E, 0x7F, 0x7D, 0x80,
  0x7F, 0x7F, 0x82, 0x7F, 0x82, 0x7F, 0x81, 0x7E, 0x7D, 0x83, 0x7C, 0x7E,
  0x80, 0x7F, 0x81, 0x7E, 0x80, 0x7F, 0x80, 0x7F, 0x7D, 0x7F, 0x80, 0x7F,
  0x7A, 0x83, 0x7E, 0x7C, 0x81, 0x7C, 0x81, 0x7E, 0x7E, 0x7D, 0x80, 0x7F,
  0x7D, 0x80, 0x7E, 0x81, 0x7D, 0x82, 0x7D, 0x80, 0x7F, 0x7D, 0x82, 0x7D,
  0x82, 0x7E, 0x80, 0x7D, 0x7F, 0x7E, 0x80, 0x80, 0x80, 0x7F, 0x80, 0x81,
  0x7E, 0x81, 0x7D, 0x80, 0x7E, 0x81, 0x7E, 0x80, 0x82, 0x7F, 0x81, 0x7D,
  0x81, 0x7E, 0x80, 0x7E, 0x7D, 0x80, 0x7E, 0x7D, 0x7F, 0x81, 0x7D, 0x7F,
  0x7D, 0x7E, 0x7F, 0x81, 0x7F, 0x7E, 0x80, 0x7D, 0x82, 0x7F, 0x7F, 0x7E,
  0x80, 0x7D, 0x7F, 0x7F, 0x7E, 0x81, 0x7D, 0x83, 0x7E, 0x82, 0x80, 0x7F,
  0x80, 0x7F, 0x82, 0x7E, 0x80, 0x80, 0x7F, 0x80, 0x7F, 0x7F, 0x81, 0x7F,
  0x83, 0x7F, 0x82, 0x83, 0x81, 0x81, 0x7F, 0x84, 0x7F, 0x80, 0x81, 0x82,
  0x81, 0x7F, 0x82, 0x80, 0x80, 0x80, 0x7F, 0x80, 0x7F, 0x81, 0x7D, 0x81,
  0x81, 0x81, 0x7F, 0x7E, 0x81, 0x80, 0x81, 0x7B, 0x82, 0x80, 0x7E, 0x80,
  0x7D, 0x83, 0x7E, 0x80, 0x80, 0x80, 0x82, 0x7F, 0x81, 0x7E, 0x82, 0x7E,
  0x7F, 0x7E, 0x80, 0x84, 0x7F, 0x82, 0x82, 0x80, 0x81, 0x81, 0x7F, 0x83,
  0x7D, 0x81, 0x7E, 0x81, 0x7F, 0x82, 0x82, 0x80, 0x84, 0x7E, 0x83, 0x7F,
  0x82, 0x7D, 0x83, 0x7F, 0x83, 0x82, 0x81, 0x84, 0x7D, 0x84, 0x7D, 0x80,
  0x80, 0x83, 0x80, 0x7F, 0x81, 0x7F, 0x80, 0x7F, 0x7F, 0x82, 0x7F, 0x83,
  0x7D, 0x84, 0x80, 0x83, 0x80, 0x7A, 0x85, 0x78, 0x85, 0x7A, 0x84, 0x7D,
  0x81, 0x81, 0x7E, 0x82, 0x7E, 0x84, 0x79, 0x83, 0x79, 0x80, 0x80, 0x7B,
  0x82, 0x7E, 0x80, 0x7F, 0x7D, 0x81, 0x7F, 0x83, 0x82, 0x82, 0x80, 0x83,
  0x7F, 0x80, 0x80, 0x7D, 0x84, 0x7C, 0x83, 0x7D, 0x82, 0x7A, 0x82, 0x7C,
  0x7D, 0x82, 0x81, 0x80, 0x81, 0x84, 0x7E, 0x86, 0x7C, 0x85, 0x7C, 0x85,
  0x7C, 0x82, 0x7E, 0x7F, 0x81, 0x7B, 0x85, 0x7D, 0x81, 0x80, 0x82, 0x7D,
  0x82, 0x80, 0x81, 0x80, 0x83, 0x80, 0x81, 0x82, 0x7F, 0x80, 0x81, 0x80,
  0x7D, 0x81, 0x7C, 0x7E, 0x7C, 0x7C, 0x7B, 0x7D, 0x7B, 0x7B, 0x7E, 0x7E,
  0x7E, 0x80, 0x7F, 0x81, 0x82, 0x80, 0x81, 0x81, 0x80, 0x80, 0x81, 0x7F,
  0x7F, 0x7D, 0x80, 0x7D, 0x7F, 0x7D, 0x7D, 0x7E, 0x7C, 0x7F, 0x7D, 0x7E,
  0x7E, 0x7F, 0x7E, 0x7E, 0x7F, 0x7E, 0x7E, 0x7F, 0x7F, 0x80, 0x7F, 0x80,
  0x7F, 0x7F, 0x7E, 0x7F, 0x7F, 0x7E, 0x7E, 0x7D, 0x7E, 0x7D, 0x7E, 0x7D,
  0x7D, 0x7D, 0x7D, 0x7E, 0x7D, 0x7D, 0x7E, 0x7E, 0x7D, 0x7E, 0x7E, 0x7F,
  0x7E, 0x7E, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7E, 0x7F, 0x7F, 0x7F, 0x7E, 0x7F, 0x7F, 0x7E, 0x7F, 0x7F, 0x7E,
  0x7F, 0x80, 0x80, 0x7F, 0x80, 0x7F, 0x7F, 0x7F, 0x7F, 0x80, 0x7F, 0x80,
  0x7E, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7E, 0x7E, 0x7E, 0x7D, 0x7E, 0x7F, 0x7F, 0x7E, 0x7F, 0x7E,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x80, 0x80, 0x80, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x80, 0x7F, 0x80, 0x7F, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x81, 0x7F, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x80, 0x80, 0x81,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x7F, 0x80, 0x7F, 0x80, 0x7F, 0x7F, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7F, 0x80,
  0x7F, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81,
  0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82,
  0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
  0x81, 0x81, 0x81, 0x82, 0x81, 0x81, 0x81, 0x82, 0x82, 0x82, 0x83, 0x83,
  0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x85, 0x84, 0x84,
  0x84, 0x84, 0x84, 0x84, 0x83, 0x83, 0x83, 0x82, 0x83, 0x82, 0x82, 0x82,
  0x81, 0x80, 0x7F, 0x7E, 0x7D, 0x7C, 0x7B, 0x79, 0x78, 0x77, 0x76, 0x75,
  0x75, 0x75, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7B, 0x7D, 0x7F, 0x80, 0x82,
  0x83, 0x85, 0x87, 0x88, 0x89, 0x89, 0x8A, 0x8A, 0x8A, 0x8A, 0x89, 0x89,
  0x88, 0x88, 0x88, 0x87, 0x87, 0x87, 0x86, 0x87, 0x89, 0x89, 0x8A, 0x8C,
  0x8E, 0x91, 0x95, 0x96, 0x8D, 0x8A, 0x8B, 0x87, 0x7D, 0x79, 0x79, 0x71,
  0x6B, 0x70, 0x70, 0x68, 0x68, 0x6C, 0x6B, 0x6C, 0x72, 0x78, 0x79, 0x7C,
  0x83, 0x87, 0x88, 0x88, 0x8A, 0x8B, 0x8A, 0x88, 0x86, 0x85, 0x82, 0x7F,
  0x7A, 0x76, 0x74, 0x72, 0x6F, 0x6D, 0x6D, 0x6C, 0x6D, 0x6F, 0x72, 0x72,
  0x75, 0x78, 0x7C, 0x7F, 0x83, 0x85, 0x87, 0x8A, 0x8D, 0x8E, 0x8E, 0x8F,
  0x8E, 0x8E, 0x8E, 0x8E, 0x8E, 0x8D, 0x8D, 0x8E, 0x8D, 0x8E, 0x90, 0x92,
  0x94, 0x97, 0x90, 0x84, 0x84, 0x81, 0x78, 0x6F, 0x6F, 0x6B, 0x63, 0x65,
  0x69, 0x62, 0x5D, 0x64, 0x68, 0x69, 0x6E, 0x79, 0x7D, 0x7D, 0x84, 0x8C,
  0x8D, 0x8D, 0x90, 0x90, 0x8E, 0x8D, 0x8E, 0x8D, 0x89, 0x85, 0x80, 0x7F,
  0x7D, 0x78, 0x75, 0x70, 0x6B, 0x6A, 0x6B, 0x69, 0x66, 0x67, 0x69, 0x6B,
  0x6F, 0x72, 0x73, 0x77, 0x7D, 0x80, 0x85, 0x8B, 0x8D, 0x8E, 0x90, 0x92,
  0x91, 0x92, 0x92, 0x8F, 0x8E, 0x8D, 0x8D, 0x8B, 0x8B, 0x8B, 0x8B, 0x8C,
  0x91, 0x93, 0x92, 0x8D, 0x81, 0x80, 0x7C, 0x75, 0x6E, 0x6C, 0x6A, 0x63,
  0x64, 0x68, 0x63, 0x60, 0x65, 0x68, 0x6C, 0x73, 0x7B, 0x7F, 0x81, 0x87,
  0x8B, 0x8C, 0x8E, 0x90, 0x8F, 0x8C, 0x8C, 0x8D, 0x89, 0x87, 0x83, 0x7E,
  0x7C, 0x7B, 0x77, 0x72, 0x71, 0x6E, 0x69, 0x69, 0x6A, 0x66, 0x65, 0x6A,
  0x6B, 0x6B, 0x6F, 0x75, 0x75, 0x78, 0x81, 0x84, 0x85, 0x8A, 0x8F, 0x8E,
  0x91, 0x93, 0x92, 0x92, 0x93, 0x92, 0x8E, 0x8E, 0x8E, 0x8C, 0x8B, 0x8E,
  0x90, 0x93, 0x94, 0x95, 0x89, 0x7D, 0x7F, 0x7A, 0x71, 0x6C, 0x6E, 0x67,
  0x60, 0x66, 0x68, 0x5F, 0x60, 0x67, 0x69, 0x6B, 0x74, 0x7D, 0x7F, 0x82,
  0x89, 0x8C, 0x8B, 0x8D, 0x8F, 0x90, 0x8B, 0x8B, 0x8C, 0x88, 0x85, 0x85,
  0x7F, 0x7A, 0x7A, 0x78, 0x72, 0x70, 0x6F, 0x6B, 0x6A, 0x6C, 0x6A, 0x68,
  0x6D, 0x6F, 0x70, 0x73, 0x77, 0x78, 0x7D, 0x82, 0x86, 0x88, 0x8B, 0x8F,
  0x8F, 0x93, 0x94, 0x94, 0x94, 0x94, 0x96, 0x92, 0x93, 0x93, 0x93, 0x93,
  0x97, 0x9A, 0x98, 0x92, 0x81, 0x83, 0x7E, 0x75, 0x70, 0x6E, 0x6A, 0x61,
  0x64, 0x69, 0x62, 0x5F, 0x67, 0x6A, 0x6A, 0x70, 0x7A, 0x7C, 0x7F, 0x86,
  0x8E, 0x89, 0x8E, 0x93, 0x91, 0x91, 0x8F, 0x93, 0x8C, 0x8A, 0x87, 0x82,
  0x7E, 0x7D, 0x7A, 0x76, 0x73, 0x6E, 0x6E, 0x6D, 0x6B, 0x68, 0x6B, 0x6D,
  0x6A, 0x70, 0x7A, 0x77, 0x7B, 0x81, 0x8A, 0x88, 0x8D, 0x95, 0x90, 0x99,
  0x9B, 0x9E, 0x9D, 0xA3, 0xA1, 0xA2, 0xA7, 0xA7, 0xA3, 0xAA, 0xA3, 0x99,
  0x83, 0x6B, 0x77, 0x5C, 0x54, 0x54, 0x58, 0x54, 0x4E, 0x67, 0x64, 0x65,
  0x77, 0x7C, 0x7E, 0x86, 0x94, 0x99, 0x8D, 0x99, 0x97, 0x93, 0x91, 0x8F,
  0x8C, 0x86, 0x8C, 0x85, 0x7E, 0x83, 0x85, 0x7A, 0x6E, 0x73, 0x70, 0x63,
  0x65, 0x64, 0x63, 0x62, 0x65, 0x6A, 0x6B, 0x76, 0x78, 0x7F, 0x89, 0x8D,
  0x95, 0x98, 0xA1, 0xA0, 0xA4, 0xA1, 0x9E, 0xA2, 0x9D, 0x9B, 0x9B, 0xA0,
  0x9B, 0x9A, 0xA0, 0xA3, 0x90, 0x8E, 0x6B, 0x6F, 0x68, 0x4A, 0x53, 0x50,
  0x5B, 0x41, 0x5F, 0x6C, 0x66, 0x72, 0x7C, 0x8A, 0x8A, 0x96, 0x98, 0x95,
  0xA1, 0x99, 0x93, 0x92, 0x93, 0x8C, 0x81, 0x8C, 0x83, 0x82, 0x7B, 0x80,
  0x7F, 0x6D, 0x6B, 0x73, 0x65, 0x5B, 0x63, 0x62, 0x5A, 0x61, 0x66, 0x67,
  0x72, 0x77, 0x79, 0x84, 0x90, 0x90, 0x96, 0xA5, 0xA3, 0xA5, 0xAA, 0xA9,
  0xAA, 0xA7, 0xA9, 0xA1, 0xAB, 0xA4, 0xA2, 0x9C, 0x96, 0x77, 0x6B, 0x72,
  0x4E, 0x4F, 0x51, 0x55, 0x40, 0x57, 0x64, 0x5D, 0x6A, 0x73, 0x81, 0x7E,
  0x8F, 0x91, 0x96, 0x9A, 0x97, 0x96, 0x95, 0x96, 0x89, 0x89, 0x8C, 0x85,
  0x7F, 0x7F, 0x83, 0x75, 0x6C, 0x71, 0x6C, 0x5F, 0x5F, 0x62, 0x60, 0x5B,
  0x63, 0x6A, 0x6C, 0x70, 0x75, 0x82, 0x8B, 0x8D, 0x98, 0xA3, 0xA5, 0xA6,
  0xAB, 0xB2, 0xA9, 0xAA, 0xAD, 0xA9, 0xA2, 0xA7, 0x99, 0x93, 0x79, 0x76,
  0x6F, 0x52, 0x59, 0x55, 0x54, 0x44, 0x5C, 0x59, 0x59, 0x62, 0x6D, 0x72,
  0x74, 0x86, 0x84, 0x8D, 0x91, 0x93, 0x93, 0x98, 0x94, 0x8F, 0x91, 0x8F,
  0x82, 0x88, 0x82, 0x7A, 0x72, 0x72, 0x6E, 0x62, 0x66, 0x5F, 0x60, 0x5C,
  0x62, 0x65, 0x6A, 0x6D, 0x75, 0x81, 0x83, 0x8C, 0x96, 0x9E, 0xA0, 0xA9,
  0xAF, 0xAD, 0xB3, 0xB2, 0xB0, 0xAE, 0xA4, 0x9F, 0x81, 0x81, 0x70, 0x61,
  0x5D, 0x5A, 0x54, 0x4B, 0x5E, 0x56, 0x5C, 0x64, 0x6C, 0x6F, 0x78, 0x81,
  0x84, 0x8A, 0x8C, 0x8F, 0x8F, 0x91, 0x8D, 0x8C, 0x8F, 0x82, 0x86, 0x83,
  0x77, 0x76, 0x71, 0x6F, 0x65, 0x6A, 0x68, 0x68, 0x64, 0x6A, 0x6D, 0x6D,
  0x72, 0x79, 0x83, 0x84, 0x90, 0x94, 0x9E, 0xA1, 0xA7, 0xAA, 0xB1, 0xB0,
  0xAD, 0xAE, 0xA7, 0x9C, 0x80, 0x89, 0x6F, 0x60, 0x61, 0x5D, 0x52, 0x4C,
  0x62, 0x53, 0x5D, 0x63, 0x6E, 0x6E, 0x77, 0x85, 0x84, 0x8F, 0x8A, 0x95,
  0x90, 0x91, 0x8C, 0x90, 0x85, 0x80, 0x82, 0x78, 0x73, 0x6F, 0x72, 0x64,
  0x6B, 0x68, 0x6A, 0x66, 0x6E, 0x6D, 0x71, 0x79, 0x7E, 0x85, 0x8F, 0x94,
  0x99, 0xA4, 0xA6, 0xAD, 0xB1, 0xB3, 0xB4, 0xB1, 0xAC, 0xA0, 0x8A, 0x8D,
  0x71, 0x6A, 0x63, 0x60, 0x50, 0x55, 0x5A, 0x51, 0x5B, 0x5E, 0x69, 0x67,
  0x79, 0x7D, 0x88, 0x89, 0x90, 0x97, 0x95, 0x96, 0x97, 0x93, 0x8C, 0x88,
  0x85, 0x7B, 0x73, 0x72, 0x6B, 0x68, 0x66, 0x6A, 0x63, 0x6A, 0x6B, 0x6E,
  0x74, 0x78, 0x83, 0x85, 0x90, 0x96, 0x9F, 0xA4, 0xAB, 0xAE, 0xB5, 0xAF,
  0xB2, 0xAA, 0x93, 0x9D, 0x80, 0x7A, 0x74, 0x6D, 0x5F, 0x5F, 0x66, 0x55,
  0x61, 0x5F, 0x64, 0x66, 0x70, 0x75, 0x7A, 0x87, 0x81, 0x8D, 0x8B, 0x8E,
  0x88, 0x8E, 0x8A, 0x7E, 0x8C, 0x7B, 0x7B, 0x78, 0x7C, 0x6F, 0x79, 0x78,
  0x72, 0x7A, 0x77, 0x7C, 0x7B, 0x83, 0x84, 0x8A, 0x90, 0x93, 0x99, 0x9E,
  0xA0, 0xA3, 0xA0, 0xA5, 0x8D, 0x94, 0x8B, 0x78, 0x7C, 0x77, 0x71, 0x68,
  0x78, 0x6C, 0x6F, 0x72, 0x73, 0x74, 0x74, 0x7B, 0x7A, 0x84, 0x7B, 0x87,
  0x85, 0x84, 0x7F, 0x82, 0x84, 0x71, 0x7D, 0x79, 0x73, 0x6B, 0x7D, 0x6F,
  0x70, 0x7A, 0x78, 0x77, 0x7E, 0x86, 0x7F, 0x8C, 0x8D, 0x93, 0x96, 0x9A,
  0xA0, 0xA4, 0xA2, 0xA3, 0xA2, 0x9C, 0x86, 0x92, 0x7D, 0x6E, 0x73, 0x6C,
  0x60, 0x60, 0x6D, 0x5D, 0x69, 0x6B, 0x70, 0x72, 0x7C, 0x7E, 0x84, 0x8B,
  0x87, 0x8F, 0x8F, 0x8C, 0x85, 0x8E, 0x80, 0x77, 0x7D, 0x78, 0x68, 0x71,
  0x73, 0x65, 0x6C, 0x73, 0x6D, 0x70, 0x7A, 0x78, 0x80, 0x85, 0x8C, 0x94,
  0x9A, 0x9B, 0xAA, 0xA8, 0xA9, 0xA7, 0xAE, 0x95, 0x92, 0x98, 0x75, 0x7A,
  0x75, 0x6C, 0x5A, 0x6C, 0x5E, 0x5B, 0x64, 0x62, 0x64, 0x6A, 0x73, 0x72,
  0x80, 0x80, 0x86, 0x8D, 0x8B, 0x86, 0x8F, 0x88, 0x7E, 0x82, 0x83, 0x72,
  0x77, 0x7D, 0x71, 0x6E, 0x7B, 0x73, 0x6D, 0x7A, 0x75, 0x77, 0x7C, 0x84,
  0x84, 0x90, 0x90, 0x9D, 0x9D, 0xA6, 0xA1, 0xA6, 0x9E, 0x8A, 0x9C, 0x7D,
  0x7D, 0x7A, 0x76, 0x64, 0x6D, 0x6E, 0x5E, 0x6C, 0x67, 0x6A, 0x6B, 0x76,
  0x73, 0x7C, 0x80, 0x7F, 0x88, 0x86, 0x82, 0x88, 0x85, 0x7D, 0x80, 0x7D,
  0x78, 0x76, 0x78, 0x75, 0x73, 0x75, 0x76, 0x74, 0x76, 0x79, 0x7C, 0x7A,
  0x84, 0x87, 0x8D, 0x8F, 0x98, 0x9C, 0x9C, 0xA2, 0x9E, 0xA0, 0x88, 0x96,
  0x83, 0x77, 0x7D, 0x73, 0x6C, 0x69, 0x73, 0x62, 0x6B, 0x6C, 0x6B, 0x6C,
  0x73, 0x76, 0x78, 0x81, 0x80, 0x86, 0x87, 0x85, 0x87, 0x88, 0x7E, 0x82,
  0x7F, 0x79, 0x78, 0x79, 0x77, 0x75, 0x75, 0x76, 0x76, 0x74, 0x7A, 0x76,
  0x7C, 0x7F, 0x83, 0x85, 0x92, 0x8F, 0x99, 0x9D, 0x9F, 0xA2, 0x9E, 0xA0,
  0x87, 0x99, 0x7E, 0x7A, 0x7B, 0x72, 0x67, 0x69, 0x73, 0x5B, 0x6F, 0x69,
  0x6B, 0x6C, 0x76, 0x78, 0x7A, 0x83, 0x81, 0x8B, 0x85, 0x87, 0x88, 0x86,
  0x7F, 0x81, 0x80, 0x74, 0x7B, 0x76, 0x76, 0x74, 0x78, 0x76, 0x76, 0x79,
  0x79, 0x7A, 0x7A, 0x81, 0x81, 0x87, 0x8B, 0x92, 0x92, 0x9C, 0x9C, 0xA2,
  0xA1, 0xA5, 0x92, 0x97, 0x90, 0x77, 0x83, 0x73, 0x6D, 0x63, 0x71, 0x5E,
  0x61, 0x6D, 0x61, 0x6A, 0x6D, 0x78, 0x73, 0x82, 0x82, 0x86, 0x8B, 0x89,
  0x8D, 0x85, 0x8D, 0x7C, 0x89, 0x7B, 0x7A, 0x7D, 0x73, 0x78, 0x73, 0x78,
  0x6D, 0x7B, 0x70, 0x75, 0x79, 0x76, 0x7B, 0x82, 0x85, 0x87, 0x96, 0x91,
  0x99, 0x9E, 0xA2, 0xA1, 0xA5, 0xA4, 0x8D, 0x9E, 0x85, 0x78, 0x82, 0x72,
  0x66, 0x6A, 0x71, 0x57, 0x6D, 0x69, 0x63, 0x6C, 0x72, 0x73, 0x77, 0x81,
  0x80, 0x86, 0x8A, 0x86, 0x8F, 0x86, 0x87, 0x8A, 0x7F, 0x81, 0x7F, 0x79,
  0x72, 0x7D, 0x6C, 0x75, 0x73, 0x72, 0x6E, 0x78, 0x73, 0x74, 0x80, 0x7B,
  0x84, 0x87, 0x8F, 0x8E, 0x9A, 0x96, 0x9E, 0xA1, 0xA4, 0xA4, 0xA5, 0x90,
  0x9B, 0x85, 0x77, 0x84, 0x6B, 0x6A, 0x66, 0x6F, 0x58, 0x6B, 0x68, 0x63,
  0x6C, 0x6F, 0x75, 0x75, 0x84, 0x7F, 0x88, 0x89, 0x8A, 0x8C, 0x8F, 0x83,
  0x8D, 0x88, 0x79, 0x85, 0x7E, 0x70, 0x77, 0x7D, 0x66, 0x77, 0x74, 0x6B,
  0x6F, 0x78, 0x72, 0x77, 0x80, 0x7C, 0x87, 0x8A, 0x8E, 0x92, 0x99, 0x96,
  0xA3, 0x9E, 0xA8, 0xA6, 0xAC, 0x91, 0x99, 0x95, 0x6F, 0x85, 0x73, 0x64,
  0x63, 0x6F, 0x59, 0x5E, 0x6C, 0x5A, 0x69, 0x6D, 0x6E, 0x78, 0x7E, 0x80,
  0x87, 0x90, 0x86, 0x96, 0x8D, 0x92, 0x8A, 0x97, 0x7C, 0x83, 0x8B, 0x67,
  0x84, 0x73, 0x73, 0x68, 0x84, 0x5E, 0x75, 0x77, 0x67, 0x75, 0x79, 0x76,
  0x7B, 0x8E, 0x79, 0x95, 0x8E, 0x8F, 0x9A, 0x9A, 0x98, 0xA3, 0xA2, 0xA4,
  0xA8, 0xA4, 0x88, 0xA1, 0x7C, 0x70, 0x83, 0x67, 0x5B, 0x64, 0x6A, 0x46,
  0x6C, 0x61, 0x5B, 0x6B, 0x72, 0x6F, 0x7B, 0x87, 0x80, 0x8F, 0x8E, 0x8D,
  0x97, 0x8D, 0x92, 0x8A, 0x8D, 0x85, 0x7F, 0x82, 0x74, 0x7E, 0x6A, 0x79,
  0x6E, 0x6C, 0x6B, 0x73, 0x67, 0x6D, 0x77, 0x6C, 0x7A, 0x79, 0x83, 0x7D,
  0x8C, 0x8A, 0x90, 0x90, 0x9A, 0x99, 0x9B, 0xA0, 0xA1, 0x9D, 0xA4, 0xA1,
  0xA9, 0x91, 0x89, 0x9E, 0x5D, 0x7E, 0x71, 0x5E, 0x54, 0x6A, 0x5D, 0x47,
  0x78, 0x56, 0x65, 0x6D, 0x73, 0x77, 0x7F, 0x8A, 0x83, 0x97, 0x8A, 0x94,
  0x95, 0x91, 0x8D, 0x91, 0x88, 0x80, 0x8A, 0x71, 0x83, 0x6F, 0x77, 0x6E,
  0x6F, 0x6D, 0x67, 0x70, 0x64, 0x6C, 0x6D, 0x70, 0x6B, 0x81, 0x71, 0x81,
  0x85, 0x85, 0x89, 0x96, 0x8E, 0x9B, 0x9D, 0x9A, 0xA0, 0x9D, 0x9F, 0x9A,
  0xA1, 0x9A, 0x9D, 0xA1, 0x93, 0x72, 0xA2, 0x55, 0x69, 0x74, 0x53, 0x51,
  0x5D, 0x69, 0x3C, 0x7A, 0x5B, 0x67, 0x73, 0x77, 0x80, 0x85, 0x91, 0x8B,
  0x9C, 0x95, 0x91, 0xA1, 0x91, 0x8C, 0x93, 0x8E, 0x7B, 0x8C, 0x7E, 0x69,
  0x88, 0x62, 0x70, 0x6F, 0x6A, 0x5C, 0x74, 0x68, 0x5C, 0x7C, 0x6B, 0x70,
  0x7C, 0x82, 0x79, 0x8E, 0x88, 0x8E, 0x94, 0x95, 0x95, 0x9C, 0x95, 0x94,
  0x9D, 0x8C, 0x91, 0x91, 0x89, 0x8C, 0x83, 0x8F, 0x7F, 0x8D, 0x8A, 0x8F,
  0x88, 0x68, 0xA4, 0x4E, 0x75, 0x7C, 0x5B, 0x62, 0x6C, 0x7A, 0x49, 0x8C,
  0x68, 0x6F, 0x80, 0x7A, 0x83, 0x84, 0x92, 0x7C, 0x9D, 0x84, 0x88, 0x95,
  0x80, 0x86, 0x87, 0x84, 0x78, 0x88, 0x7C, 0x7C, 0x80, 0x7D, 0x72, 0x83,
  0x73, 0x6C, 0x80, 0x6B, 0x6E, 0x73, 0x77, 0x65, 0x7A, 0x76, 0x70, 0x7D,
  0x79, 0x7F, 0x82, 0x7E, 0x8E, 0x86, 0x87, 0x92, 0x8A, 0x8D, 0x8A, 0x94,
  0x86, 0x88, 0x91, 0x85, 0x83, 0x8D, 0x84, 0x80, 0x83, 0x8A, 0x79, 0x8E,
  0x86, 0x93, 0x76, 0x7F, 0x9B, 0x4D, 0x8D, 0x73, 0x6C, 0x5F, 0x84, 0x70,
  0x58, 0x96, 0x65, 0x7C, 0x7A, 0x8B, 0x7B, 0x89, 0x97, 0x7D, 0x9B, 0x8C,
  0x89, 0x91, 0x89, 0x85, 0x83, 0x8C, 0x73, 0x88, 0x7A, 0x79, 0x7F, 0x75,
  0x82, 0x72, 0x83, 0x73, 0x84, 0x72, 0x71, 0x81, 0x6D, 0x6F, 0x7D, 0x7A,
  0x68, 0x89, 0x7B, 0x76, 0x88, 0x81, 0x80, 0x85, 0x89, 0x81, 0x8C, 0x87,
  0x83, 0x8F, 0x84, 0x82, 0x87, 0x85, 0x7B, 0x87, 0x80, 0x7E, 0x83, 0x7F,
  0x85, 0x82, 0x85, 0x85, 0x8B, 0x89, 0x90, 0x91, 0x9A, 0x71, 0xA2, 0x7E,
  0x67, 0x93, 0x6B, 0x6E, 0x66, 0x87, 0x52, 0x78, 0x78, 0x64, 0x7D, 0x72,
  0x80, 0x7A, 0x8B, 0x7D, 0x8A, 0x90, 0x7C, 0x91, 0x8A, 0x82, 0x87, 0x8C,
  0x82, 0x80, 0x93, 0x79, 0x8A, 0x89, 0x84, 0x86, 0x89, 0x84, 0x80, 0x8A,
  0x79, 0x81, 0x80, 0x79, 0x7A, 0x7D, 0x78, 0x68, 0x76, 0x6E, 0x63, 0x71,
  0x75, 0x70, 0x70, 0x85, 0x77, 0x7F, 0x83, 0x86, 0x83, 0x85, 0x8F, 0x84,
  0x92, 0x86, 0x8F, 0x8A, 0x87, 0x88, 0x86, 0x87, 0x7F, 0x8D, 0x7E, 0x88,
  0x81, 0x87, 0x82, 0x8E, 0x83, 0x95, 0x7E, 0x78, 0x9C, 0x53, 0x8A, 0x72,
  0x6B, 0x68, 0x79, 0x76, 0x5C, 0x91, 0x6B, 0x7A, 0x84, 0x82, 0x84, 0x88,
  0x91, 0x7F, 0x95, 0x8A, 0x7E, 0x97, 0x7D, 0x85, 0x84, 0x86, 0x7A, 0x83,
  0x83, 0x76, 0x86, 0x7B, 0x80, 0x7B, 0x84, 0x76, 0x80, 0x7E, 0x76, 0x80,
  0x7A, 0x7D, 0x78, 0x81, 0x79, 0x7A, 0x80, 0x7A, 0x7C, 0x81, 0x78, 0x76,
  0x7D, 0x71, 0x76, 0x78, 0x75, 0x75, 0x7B, 0x7A, 0x7A, 0x80, 0x7E, 0x7F,
  0x85, 0x83, 0x87, 0x8C, 0x87, 0x8A, 0x8C, 0x8A, 0x84, 0x8D, 0x83, 0x84,
  0x85, 0x83, 0x80, 0x86, 0x81, 0x86, 0x8A, 0x88, 0x87, 0x74, 0x98, 0x5F,
  0x7E, 0x7B, 0x65, 0x71, 0x6B, 0x80, 0x59, 0x89, 0x6F, 0x73, 0x85, 0x73,
  0x8A, 0x7F, 0x8C, 0x83, 0x8E, 0x90, 0x7C, 0x96, 0x86, 0x80, 0x89, 0x88,
  0x7C, 0x7E, 0x88, 0x72, 0x80, 0x7C, 0x79, 0x7A, 0x7C, 0x7A, 0x78, 0x7E,
  0x76, 0x7C, 0x7C, 0x79, 0x7E, 0x7E, 0x7D, 0x7D, 0x83, 0x7D, 0x81, 0x83,
  0x81, 0x83, 0x83, 0x83, 0x81, 0x82, 0x74, 0x7F, 0x74, 0x6F, 0x77, 0x73,
  0x73, 0x73, 0x7F, 0x74, 0x7F, 0x7F, 0x7D, 0x84, 0x84, 0x86, 0x88, 0x8C,
  0x85, 0x8D, 0x89, 0x87, 0x88, 0x87, 0x84, 0x83, 0x86, 0x81, 0x85, 0x88,
  0x82, 0x8D, 0x8A, 0x71, 0x92, 0x74, 0x6D, 0x83, 0x6C, 0x73, 0x69, 0x80,
  0x68, 0x74, 0x7F, 0x6C, 0x84, 0x78, 0x83, 0x84, 0x8A, 0x88, 0x88, 0x94,
  0x85, 0x8C, 0x8B, 0x88, 0x82, 0x83, 0x86, 0x79, 0x81, 0x7B, 0x7B, 0x7D,
  0x78, 0x7B, 0x7D, 0x7A, 0x75, 0x81, 0x7B, 0x78, 0x81, 0x7D, 0x80, 0x7E,
  0x83, 0x81, 0x81, 0x82, 0x82, 0x84, 0x84, 0x83, 0x84, 0x87, 0x82, 0x83,
  0x85, 0x7D, 0x74, 0x7B, 0x74, 0x69, 0x74, 0x73, 0x6A, 0x73, 0x79, 0x73,
  0x7B, 0x7F, 0x7E, 0x84, 0x86, 0x87, 0x8C, 0x8E, 0x8A, 0x8D, 0x8E, 0x88,
  0x87, 0x89, 0x83, 0x83, 0x85, 0x81, 0x84, 0x86, 0x83, 0x87, 0x8A, 0x7D,
  0x81, 0x85, 0x73, 0x78, 0x7A, 0x74, 0x70, 0x76, 0x79, 0x71, 0x7C, 0x7A,
  0x7C, 0x82, 0x80, 0x85, 0x88, 0x8C, 0x85, 0x8D, 0x8E, 0x84, 0x88, 0x87,
  0x84, 0x7E, 0x82, 0x7F, 0x7B, 0x7F, 0x79, 0x7D, 0x7E, 0x7A, 0x7D, 0x7F,
  0x7D, 0x7C, 0x80, 0x7F, 0x7F, 0x80, 0x7F, 0x80, 0x81, 0x80, 0x7F, 0x82,
  0x80, 0x80, 0x82, 0x83, 0x80, 0x84, 0x83, 0x80, 0x85, 0x80, 0x82, 0x78,
  0x78, 0x7A, 0x6F, 0x74, 0x72, 0x76, 0x73, 0x77, 0x7D, 0x7A, 0x83, 0x80,
  0x85, 0x88, 0x88, 0x8A, 0x8C, 0x8D, 0x8A, 0x8B, 0x8A, 0x87, 0x86, 0x83,
  0x83, 0x83, 0x80, 0x82, 0x81, 0x83, 0x83, 0x82, 0x88, 0x82, 0x7F, 0x81,
  0x7D, 0x7A, 0x79, 0x79, 0x76, 0x76, 0x79, 0x77, 0x7A, 0x7C, 0x7C, 0x80,
  0x82, 0x84, 0x86, 0x88, 0x89, 0x88, 0x88, 0x88, 0x84, 0x84, 0x82, 0x80,
  0x7F, 0x7D, 0x7D, 0x7C, 0x7B, 0x7D, 0x7C, 0x7C, 0x7D, 0x7F, 0x7E, 0x7E,
  0x80, 0x80, 0x7E, 0x7F, 0x80, 0x7E, 0x7F, 0x7F, 0x7F, 0x7E, 0x7F, 0x80,
  0x81, 0x82, 0x83, 0x83, 0x84, 0x84, 0x82, 0x84, 0x81, 0x81, 0x78, 0x79,
  0x79, 0x73, 0x74, 0x73, 0x76, 0x74, 0x78, 0x7A, 0x7B, 0x7E, 0x81, 0x81,
  0x84, 0x87, 0x88, 0x88, 0x89, 0x89, 0x86, 0x87, 0x85, 0x83, 0x82, 0x81,
  0x81, 0x80, 0x82, 0x81, 0x82, 0x84, 0x83, 0x85, 0x84, 0x84, 0x82, 0x7E,
  0x7E, 0x7B, 0x7A, 0x78, 0x78, 0x78, 0x77, 0x7A, 0x7A, 0x7B, 0x7E, 0x80,
  0x82, 0x84, 0x85, 0x86, 0x86, 0x86, 0x86, 0x85, 0x83, 0x82, 0x81, 0x80,
  0x80, 0x7F, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7F, 0x7E, 0x7E,
  0x7E, 0x7E, 0x7D, 0x7D, 0x7D, 0x7D, 0x7D, 0x7E, 0x7E, 0x7E, 0x80, 0x80,
  0x80, 0x81, 0x82, 0x82, 0x82, 0x82, 0x81, 0x82, 0x81, 0x80, 0x80, 0x7F,
  0x7E, 0x7D, 0x79, 0x78, 0x77, 0x76, 0x76, 0x77, 0x77, 0x76, 0x78, 0x7A,
  0x79, 0x7A, 0x7C, 0x7D, 0x7E, 0x80, 0x83, 0x83, 0x85, 0x86, 0x86, 0x87,
  0x87, 0x87, 0x87, 0x87, 0x86, 0x85, 0x85, 0x84, 0x83, 0x82, 0x82, 0x81,
  0x80, 0x80, 0x7E, 0x7D, 0x7D, 0x7C, 0x7B, 0x7B, 0x7B, 0x7A, 0x7A, 0x7B,
  0x7A, 0x7A, 0x7B, 0x7B, 0x7B, 0x7D, 0x7D, 0x7E, 0x7F, 0x80, 0x80, 0x81,
  0x82, 0x82, 0x82, 0x81, 0x81, 0x81, 0x80, 0x7F, 0x7F, 0x7E, 0x7D, 0x7D,
  0x7C, 0x7B, 0x7C, 0x7B, 0x7B, 0x7C, 0x7C, 0x7C, 0x7D, 0x7D, 0x7D, 0x7E,
  0x7E, 0x7F, 0x7F, 0x80, 0x80, 0x80, 0x81, 0x80, 0x81, 0x81, 0x80, 0x80,
  0x80, 0x80, 0x7F, 0x7F, 0x7F, 0x7D, 0x7B, 0x7A, 0x79, 0x79, 0x78, 0x78,
  0x78, 0x77, 0x79, 0x7A, 0x79, 0x7B, 0x7C, 0x7D, 0x7E, 0x81, 0x82, 0x83,
  0x84, 0x85, 0x85, 0x86, 0x86, 0x85, 0x85, 0x84, 0x84, 0x83, 0x83, 0x83,
  0x82, 0x82, 0x82, 0x81, 0x81, 0x81, 0x81, 0x80, 0x7F, 0x7F, 0x7E, 0x7E,
  0x7D, 0x7D, 0x7C, 0x7C, 0x7C, 0x7C, 0x7C, 0x7D, 0x7E, 0x7E, 0x7F, 0x80,
  0x80, 0x81, 0x82, 0x82, 0x83, 0x83, 0x83, 0x83, 0x84, 0x83, 0x82, 0x82,
  0x82, 0x81, 0x81, 0x81, 0x80, 0x7F, 0x7F, 0x7E, 0x7E, 0x7E, 0x7F, 0x7E,
  0x7F, 0x7F, 0x7F, 0x80, 0x80, 0x81, 0x80, 0x81, 0x81, 0x81, 0x81, 0x82,
  0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x80, 0x80, 0x7F, 0x7D, 0x7D, 0x7C,
  0x7C, 0x7B, 0x7B, 0x7B, 0x7A, 0x7B, 0x7C, 0x7B, 0x7C, 0x7D, 0x7E, 0x7E,
  0x80, 0x82, 0x83, 0x84, 0x86, 0x87, 0x87, 0x88, 0x88, 0x88, 0x87, 0x87,
  0x86, 0x86, 0x85, 0x84, 0x84, 0x83, 0x83, 0x82, 0x82, 0x82, 0x81, 0x80,
  0x80, 0x7F, 0x7E, 0x7E, 0x7E, 0x7D, 0x7D, 0x7C, 0x7C, 0x7C, 0x7C, 0x7C,
  0x7C, 0x7D, 0x7E, 0x7F, 0x80, 0x81, 0x81, 0x83, 0x83, 0x84, 0x84, 0x84,
  0x84, 0x84, 0x84, 0x83, 0x82, 0x82, 0x81, 0x81, 0x80, 0x7F, 0x7F, 0x7E,
  0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7F, 0x7F, 0x7F, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x82, 0x82, 0x82, 0x82, 0x81,
  0x81, 0x81, 0x81, 0x80, 0x80, 0x7F, 0x7F, 0x7C, 0x7A, 0x7B, 0x79, 0x79,
  0x79, 0x79, 0x79, 0x79, 0x7B, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x80, 0x82,
  0x82, 0x83, 0x84, 0x84, 0x84, 0x84, 0x84, 0x83, 0x83, 0x83, 0x83, 0x82,
  0x82, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7F, 0x7F,
  0x7F, 0x7E, 0x7E, 0x7E, 0x7E, 0x7D, 0x7D, 0x7E, 0x7D, 0x7E, 0x7E, 0x7E,
  0x7F, 0x7F, 0x7F, 0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
  0x81, 0x80, 0x80, 0x80, 0x7F, 0x7F, 0x7F, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E,
  0x7E, 0x7E, 0x7E, 0x7E, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x80, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x80, 0x80, 0x80, 0x7F, 0x7E, 0x7F, 0x7E, 0x7E, 0x7E, 0x7E,
  0x7E, 0x7E, 0x7E, 0x7F, 0x7E, 0x7E, 0x7F, 0x7E, 0x7F, 0x7F, 0x80, 0x80,
  0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x82, 0x81, 0x81, 0x81,
  0x81, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x80,
  0x80, 0x80, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7E, 0x7E, 0x7F,
  0x7E, 0x7F, 0x7F, 0x7F, 0x7F, 0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x81,
  0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x7F, 0x80, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7F, 0x7E, 0x7E, 0x7E, 0x7E,
  0x7E, 0x7E, 0x7E, 0x7D, 0x7E, 0x7E, 0x7E, 0x7E, 0x7F, 0x7F, 0x7F, 0x80,
  0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
  0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80
};

#endif