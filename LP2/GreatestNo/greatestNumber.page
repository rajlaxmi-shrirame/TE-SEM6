<apex:page controller="GreatestNumberFinder">
    <apex:form>
        <apex:pageBlock title="Enter Three Numbers">
            <apex:pageBlockSection>
                <apex:inputText value="{!number1}" label="Number 1"/>
            </apex:pageBlockSection>
            <apex:pageBlockSection>
                <apex:inputText value="{!number2}" label="Number 2"/>
            </apex:pageBlockSection>
            <apex:pageBlockSection>
                <apex:inputText value="{!number3}" label="Number 3"/>
            </apex:pageBlockSection>
            <apex:pageBlockButtons>
                <apex:commandButton action="{!findGreatestNumber}" value="Find Greatest Number"/>
            </apex:pageBlockButtons>
        </apex:pageBlock>
        
        <apex:outputPanel rendered="{!greatestNumber != 0}">
            <apex:pageBlock title="Result">
                <apex:outputText value="The greatest number among {!number1}, {!number2}, and {!number3} is: {!greatestNumber}"/>
            </apex:pageBlock>
        </apex:outputPanel>
    </apex:form>
</apex:page>
