//
//  GamePlayLayer.h
//  QBoard
//
//  Created by Choe Yong-uk on 12. 1. 23..
//  Copyright noizze.net 2012년. All rights reserved.
//


// When you import this file, you import all the cocos2d classes
#import "cocos2d.h"
#import "aBlock.h"

// GamePlayLayer
@interface GamePlayLayer : CCLayer
{
  
  // 설정파일값 
  BOOL effectSound_config;
  BOOL flip_config;
  
  NSMutableArray *blocks;     // 바닥에 깔린 블록들 
  NSMutableArray *hintBlocks; // 힌트로 사용 될 블록들 
  NSMutableArray *blkQueue;   // 6colours * 6shapes * 2set = 64개 블록이 초기화 되면 목록별로 들어감 
  
  int map[40][40];        // 바닥에 깔린 블록들의 매트릭스 40x40 블록이 깔리면 1씩 카운트가 올라가서 
                          // blocks 의 objectAtIndex 값에 해당하는 정수가 들어감 시작은 중앙이니까 20,20에서 시작 
  int map_mask[40][40];   // 놓여질 수 있는 위치를 표시하기 위해 사용하는 배열 

  int selectedBlock;      // 선택한 블록 
  int readyIndex;         //레디블록/opp레디블록의 몇번째 인덱스인지를 저장
  
  int myScore;
  int oppScore;
  int bonusScore;
  BOOL firstTurn; // 게임이 시작 되기 위해 첫 1블록을 두는 모드인경우에만 YES
  BOOL myTurn; // 내 턴이면 YES 상대 턴이면 NO

  CCSprite *blackBg; // 대기중 블록을 위한 오른쪽 자리 
  CCSprite *passButton; // 오른쪽 아래 패스 버튼 
  
  NSMutableArray *readyBlocks; // 블록큐 0-5 인데 굳이 필요 할까 ? 화면에 출력하고 애니메이션 하기 위함이긴 한데 
  NSMutableArray *opponentReadyBlocks; // 상대방의 블록 큐 
  
  BOOL amIopponent; // 온라인 대전 등을 할 때 내가 클라이언트 모드인가를 표시 ?
  
  CGPoint diffCamera; // 스크롤 때문에 이동 된 좌표 차이 
}

// returns a CCScene that contains the GamePlayLayer as the only child
+(CCScene *) scene;

-(void)setBlock:(int)idx x:(int)x y:(int)y;
-(CGPoint) fromMapToPosition:(int)x y:(int)y; // xy 좌표로 ccp 값을 돌려 받는 메쏘드

-(BOOL) possibleTo:(NSString*)dir blockType:(_block_type)tb blockColor:(_block_color)cb x:(int)x y:(int)y;
-(BOOL) possibleGuess:(int)idx x:(int)x y:(int)y;

-(NSString *)blockTypeFileName:(_block_type)blockType blockColor:(_block_color)blockColor; // 중복정의 
-(void) realignSixBlocksInQueue;
-(void) removeReadyBlocks;
-(void) removeHintBlocks;
-(void) drawScore;
-(void) popAlert1;
-(void) popAlert2;

-(void) blockAnimation_step1:(id)sender data:(int)idx;
-(void) blockAnimation_step3;

@end
