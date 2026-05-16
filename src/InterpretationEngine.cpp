#include "InterpretationEngine.h"

string InterpretationEngine::interpret(const ClassificationResult& result) const {
    string interpretation;

    if (result.getProfileType() == "Triad") {
        interpretation += "You are highly adaptable with strengths across multiple cognitive styles.\n";
    } else if (result.getProfileType() == "Dual") {
        interpretation += "You have two strong cognitive drivers that shape your behavior.\n";
    } else if (result.getProfileType() == "Dominant") {
        interpretation += "You rely heavily on a single dominant cognitive approach.\n";
    } else {
        interpretation += "You show a balanced but less pronounced cognitive pattern.\n";
    }

    Trait dominant = result.getDominant();
    Trait secondary = result.getSecondary();

    interpretation += "\n\t\tYour cognitive style: ";

    if (dominant == Trait::PatternHunter && secondary == Trait::SocialSmart) {
        interpretation += "\n\t\t\tStrategic Communicator - You combine logic with social awareness.";
    } else if (dominant == Trait::PatternHunter && secondary == Trait::Explorer) {
        interpretation += "\n\t\t\tAnalytical Explorer - You seek patterns while exploring new ideas.";
    } else if (dominant == Trait::PatternHunter && secondary == Trait::Stabilizer) {
        interpretation += "\n\t\t\tStructured Thinker - You value logic with stability.";
    } else if (dominant == Trait::SocialSmart && secondary == Trait::PatternHunter) {
        interpretation += "\n\t\t\tEmpathic Analyst - You read people deeply and back it with sharp logical thinking.";
    } else if (dominant == Trait::SocialSmart && secondary == Trait::Explorer) {
        interpretation += "\n\t\t\tAdaptive Connector - You explore through people and interaction.";
    } else if (dominant == Trait::SocialSmart && secondary == Trait::Stabilizer) {
        interpretation += "\n\t\t\tSupportive Organizer - You balance people and structure.";
    } else if (dominant == Trait::Explorer && secondary == Trait::PatternHunter) {
        interpretation += "\n\t\t\tCurious Investigator - You experiment freely but always search for the underlying logic.";
    } else if (dominant == Trait::Explorer && secondary == Trait::SocialSmart) {
        interpretation += "\n\t\t\tCreative Collaborator - You chase new ideas and bring others along with you.";
    } else if (dominant == Trait::Explorer && secondary == Trait::Stabilizer) {
        interpretation += "\n\t\t\tBalanced Executor - You explore but maintain control and consistency.";
    } else if (dominant == Trait::Stabilizer && secondary == Trait::PatternHunter) {
        interpretation += "\n\t\t\tPrecise Planner - You build reliable systems grounded in deep analytical thinking.";
    } else if (dominant == Trait::Stabilizer && secondary == Trait::SocialSmart) {
        interpretation += "\n\t\t\tSteady Supporter - You create safe, consistent environments where people feel secure.";
    } else if (dominant == Trait::Stabilizer && secondary == Trait::Explorer) {
        interpretation += "\n\t\t\tCautious Innovator - You are open to new ideas but only move when the ground feels solid.";
    } else {
        interpretation += "\n\t\t\tUnique combination of traits.";
    }

    interpretation += "\n\n\t\tDominant Trait Insight: ";

    switch (dominant) {
        case Trait::PatternHunter:
            interpretation += "\n\t\t\tYou naturally analyze patterns and systems.";
            break;
        case Trait::SocialSmart:
            interpretation += "\n\t\t\tYou understand and navigate social dynamics effectively.";
            break;
        case Trait::Explorer:
            interpretation += "\n\t\t\tYou are driven by curiosity and experimentation.";
            break;
        case Trait::Stabilizer:
            interpretation += "\n\t\t\tYou value consistency, structure, and reliability.";
            break;
    }

    return interpretation;
}

