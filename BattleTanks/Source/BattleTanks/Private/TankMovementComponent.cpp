// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankTracks.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::Initialize(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet) {

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	UE_LOG(LogTemp, Warning, TEXT("TracksToSet are Setup"))
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	//Find the vector the Tank is facing and where we want it to face
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	
	//DotProduct returns the cosine of the resulting vector multiplication to tell 
	//the tanks how to get a side shot on the player tank
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);

	auto RightThrow = FVector::CrossProduct(AIForwardIntention, TankForward);
	IntendTurnRight(RightThrow.Z);

	//Pass the DotProduct result into the IntendMoveForward
	IntendMoveForward(ForwardThrow);


}

void UTankMovementComponent::IntendMoveForward(float Throw) {
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	//TODO Prevent Duplicate Speed Input
}

void UTankMovementComponent::IntendTurnRight(float Throw) {
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}
