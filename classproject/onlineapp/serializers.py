from onlineapp.models import *
from rest_framework import routers, serializers, viewsets

class CollegeSerializer(serializers.ModelSerializer):
    class Meta:
        model = College
        fields = ('name','location','acronym','contact','id')


class MockSerializer(serializers.ModelSerializer):
    class Meta:
        model = MockTest1
        fields = ('id','problem1','problem2','problem3','problem4','total')


class StudentSerializer(serializers.ModelSerializer):
    mocktest1 = MockSerializer(MockTest1)
    class Meta:
        model = Student
        fields = ('id','name','dob','email','db_folder','dropped_out','college','mocktest1')

    def create(self, validated_data):
        mocktest1 = validated_data.pop('mocktest1')
        mocktest1['total'] = mocktest1['problem1'] + mocktest1['problem2'] + mocktest1['problem3'] +mocktest1['problem4']
        student = Student.objects.create(**validated_data)
        MockTest1.objects.create(student=student, **mocktest1)
        return student

    def update(self, instance, validated_data):
        mocktest1 = validated_data.pop('mocktest1')
        mocktest1['total'] = mocktest1['problem1'] + mocktest1['problem2'] + mocktest1['problem3'] +mocktest1['problem4']
        student = Student.objects.get(id=id)
        mocktest1 = MockTest1.objects.get(student=id)

        mocktest1.save()
        student.save()


